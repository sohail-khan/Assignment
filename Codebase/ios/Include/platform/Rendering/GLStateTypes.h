// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Graphics.h"

#ifdef EEGEO_WIN
#define EEGEO_GL_API_CALL __stdcall
#else
#define EEGEO_GL_API_CALL
#endif

namespace Eegeo
{
    namespace Rendering
    {
        class GLStateBase
        {
        public:
            GLStateBase()
            : m_numOfActualSets(0)
            , m_stateValid(false)
            , m_stateFilteringEnabled(true)
            , m_trySetAttempted(false)
            , m_numOfAttemptedSets(0)
            {
            }
            
            GLStateBase(bool enableStateFiltering)
            : m_stateValid(false)
            , m_stateFilteringEnabled(enableStateFiltering)
            {
            }
            
            inline void Invalidate()
            {
                m_stateValid = false;
            }
            
            inline int GetNumOfAttemptedSets() const
            {
                return m_numOfAttemptedSets;
            }
            
            inline int GetNumOfActualSets() const
            {
                return m_numOfActualSets;
            }
            
            inline void ResetCounters()
            {
                m_numOfAttemptedSets = 0;
                m_numOfActualSets = 0;
            }
            
            inline void SetTrySetAttempted()
            {
                m_trySetAttempted = true;
                ++m_numOfAttemptedSets;
            }
            
            inline void ClearTrySetAttempted()
            {
                m_trySetAttempted = false;
            }
            
            inline bool TrySetAttempted() const
            {
                return m_trySetAttempted;
            }
            
            inline bool IsStateValid() const
            {
                return m_stateValid;
            }
            
        protected:
            int m_numOfActualSets;
            
            inline void SetIsValid()
            {
                m_stateValid = m_stateFilteringEnabled;
            }
            
        private:
            bool m_stateValid;
            bool m_stateFilteringEnabled;
            bool m_trySetAttempted;
            int m_numOfAttemptedSets;
        };

        template<GLenum T_cap>
        class GLBoolState : public GLStateBase
        {
        public:
            GLBoolState(const bool value)
            : m_value(value)
            {
            }
            
            inline void Enable()
            {
                TrySet(true);
            }
            
            inline void Disable()
            {
                TrySet(false);
            }
            
            inline void operator () (bool enable)
            {
                TrySet(enable);
            }
            
            inline bool TrySet(bool value)
            {
                SetTrySetAttempted();
                
                if (!IsStateValid() || value != m_value)
                {
                    ++m_numOfActualSets;
                    
                    m_value = value;
                    SetIsValid();
                    if (value)
                    {
                        Eegeo_GL(glEnable(T_cap));
                    }
                    else
                    {
                        Eegeo_GL(glDisable(T_cap));
                    }
                    return true;
                }
                return false;
            }
            
            inline bool TrySet(const GLBoolState& stateToSet)
            {
                if(stateToSet.IsStateValid())
                {
                    return TrySet(stateToSet.m_value);
                }
                
                Eegeo_ASSERT(IsStateValid() == false, "Can't set a valid from an invalid state");
                return false;
            }
            
            inline bool TrySetIfNotAttempted(const GLBoolState& stateToSet)
            {
                if(!TrySetAttempted())
                {
                    return TrySet(stateToSet);
                }
                
                return false;
            }

            
        private:
            bool m_value;
        };

        template<typename T_paramA>
        class GLStateFunc1 : public GLStateBase
        {
        public:
            GLStateFunc1(void (EEGEO_GL_API_CALL *func)(T_paramA))
            : m_func(func)
            {
            }
            
            inline void operator () (T_paramA paramA)
            {
                TrySet(paramA);
            }
            
            inline bool TrySet(T_paramA paramA)
            {
                SetTrySetAttempted();
                
                if (!IsStateValid() ||
                    paramA != m_paramA)
                {
                    ++m_numOfActualSets;
                    m_paramA = paramA;
                    SetIsValid();
                    Eegeo_GL(m_func(paramA));
                    return true;
                }
                return false;
            }
            
            inline bool TrySet(const GLStateFunc1& stateToSet)
            {
                if(stateToSet.IsStateValid())
                {
                    return TrySet(stateToSet.m_paramA);
                }
                
                Eegeo_ASSERT(IsStateValid() == false, "Can't set a valid from an invalid state");
                return false;
            }
            
            inline bool TrySetIfNotAttempted(const GLStateFunc1& stateToSet)
            {
                if(!TrySetAttempted())
                {
                    return TrySet(stateToSet);
                }
                
                return false;
            }

            
            inline T_paramA GetValue() const
            {
                return m_paramA;
            }
            
        private:
            void (EEGEO_GL_API_CALL *m_func)(T_paramA);
            T_paramA m_paramA;
        };

        template<typename T_paramA, typename T_paramB>
        class GLStateFunc2 : public GLStateBase
        {
        public:
            GLStateFunc2(void (EEGEO_GL_API_CALL *func)(T_paramA, T_paramB))
            : m_func(func)
            {
            }
            
            inline void operator () (T_paramA paramA, T_paramB paramB)
            {
                TrySet(paramA, paramB);
            }
            
            inline bool TrySet(T_paramA paramA, T_paramB paramB)
            {
                SetTrySetAttempted();
                
                if (!IsStateValid() ||
                    (paramA != m_paramA) ||
                    (paramB != m_paramB))
                {
                    ++m_numOfActualSets;
        #pragma clang diagnostic push
        #pragma clang diagnostic ignored "-Wunknown-pragmas"
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
                    m_paramA = paramA;
                    m_paramB = paramB;
                    SetIsValid();
                    Eegeo_GL(m_func(paramA, paramB));
        #pragma GCC diagnostic pop
        #pragma clang diagnostic pop
                    return true;
                }
                return false;
            }
            
            inline bool TrySet(const GLStateFunc2& stateToSet)
            {
                if(stateToSet.IsStateValid())
                {
                    return TrySet(stateToSet.m_paramA, stateToSet.m_paramB);
                }
                
                Eegeo_ASSERT(IsStateValid() == false, "Can't set a valid from an invalid state");
                return false;
            }
            
            
            inline bool TrySetIfNotAttempted(const GLStateFunc2& stateToSet)
            {
                if(!TrySetAttempted())
                {
                    return TrySet(stateToSet);
                }
                
                return false;
            }

            
        private:
            void (EEGEO_GL_API_CALL *m_func)(T_paramA, T_paramB);
            T_paramA m_paramA;
            T_paramB m_paramB;
        };

        template<typename T_paramA, typename T_paramB, typename T_paramC>
        class GLStateFunc3 : public GLStateBase
        {
        public:
            GLStateFunc3(void (EEGEO_GL_API_CALL *func)(T_paramA, T_paramB, T_paramC))
            : m_func(func)
            {
            }
            
            inline void operator () (T_paramA paramA, T_paramB paramB, T_paramC paramC)
            {
                TrySet(paramA, paramB, paramC);
            }
            
            inline bool TrySet(T_paramA paramA, T_paramB paramB, T_paramC paramC)
            {
                SetTrySetAttempted();
                
                if (!IsStateValid() ||
                    (paramA != m_paramA) ||
                    (paramB != m_paramB) ||
                    (paramC != m_paramC))
                {
                    ++m_numOfActualSets;
                    
                    m_paramA = paramA;
                    m_paramB = paramB;
                    m_paramC = paramC;
                    SetIsValid();
                    Eegeo_GL(m_func(paramA, paramB, paramC));
                    return true;
                }
                return false;
            }
            
            inline bool TrySet(const GLStateFunc3& stateToSet)
            {
                if(stateToSet.IsStateValid())
                {
                    return TrySet(stateToSet.m_paramA, stateToSet.m_paramB, stateToSet.m_paramC);
                }
                
                Eegeo_ASSERT(IsStateValid() == false, "Can't set a valid from an invalid state");
                return false;
            }
            
            inline bool TrySetIfNotAttempted(const GLStateFunc3& stateToSet)
            {
                if(!TrySetAttempted())
                {
                    return TrySet(stateToSet);
                }

                return false;
            }

            
        private:
            void (EEGEO_GL_API_CALL *m_func)(T_paramA, T_paramB, T_paramC);
            T_paramA m_paramA;
            T_paramB m_paramB;
            T_paramC m_paramC;
        };

        template<typename T_paramA, typename T_paramB, typename T_paramC, typename T_paramD>
        class GLStateFunc4 : public GLStateBase
        {
        public:
            GLStateFunc4(void (EEGEO_GL_API_CALL *func)(T_paramA, T_paramB, T_paramC, T_paramD))
            : m_func(func)
            {
            }
            
            inline void operator () (T_paramA paramA, T_paramB paramB, T_paramC paramC, T_paramD paramD)
            {
                TrySet(paramA, paramB, paramC, paramD);
            }
            
            inline bool TrySet(T_paramA paramA, T_paramB paramB, T_paramC paramC, T_paramD paramD)
            {
                SetTrySetAttempted();
                
                if (!IsStateValid() ||
                    (paramA != m_paramA) ||
                    (paramB != m_paramB) ||
                    (paramC != m_paramC) ||
                    (paramD != m_paramD))
                {
                    ++m_numOfActualSets;
                    
                    m_paramA = paramA;
                    m_paramB = paramB;
                    m_paramC = paramC;
                    m_paramD = paramD;
                    SetIsValid();
                    Eegeo_GL(m_func(paramA, paramB, paramC, paramD));
                    return true;
                }
                return false;
            }
            
            inline bool TrySet(const GLStateFunc4& stateToSet)
            {
                if(stateToSet.IsStateValid())
                {
                    return TrySet(stateToSet.m_paramA, stateToSet.m_paramB, stateToSet.m_paramC, stateToSet.m_paramD);
                }
                
                Eegeo_ASSERT(IsStateValid() == false, "Can't set a valid from an invalid state");
                return false;
            }
            
            inline bool TrySetIfNotAttempted(const GLStateFunc4& stateToSet)
            {
                if(!TrySetAttempted())
                {
                    return TrySet(stateToSet);
                }
                
                return false;
            }
            
        private:
            void (EEGEO_GL_API_CALL *m_func)(T_paramA, T_paramB, T_paramC, T_paramD);
            T_paramA m_paramA;
            T_paramB m_paramB;
            T_paramC m_paramC;
            T_paramD m_paramD;
        };


        template<GLenum T_glEnum, typename T_paramA>
        class GLStateEnumFunc1 : public GLStateBase
        {
        public:
            GLStateEnumFunc1(void (EEGEO_GL_API_CALL *func)(GLenum, T_paramA))
            : m_func(func)
            {
            }
            
            GLStateEnumFunc1()
            : m_func(NULL)
            {
            }
            
            GLStateEnumFunc1(const GLStateEnumFunc1<T_glEnum, T_paramA>& other)
            : GLStateBase(other)
            , m_func(other.m_func)
            {
            }
            
            GLStateEnumFunc1(void (EEGEO_GL_API_CALL *func)(GLenum, T_paramA), bool enableStateFiltering)
            : GLStateBase(enableStateFiltering)
            , m_func(func)
            {
            }
            
            inline void operator () (T_paramA paramA)
            {
                TrySet(paramA);
            }
            
            inline bool TrySet(T_paramA paramA)
            {
                SetTrySetAttempted();
                
                if (!IsStateValid() ||
                    paramA != m_paramA)
                {
                    ++m_numOfActualSets;
                    
                    m_paramA = paramA;
                    SetIsValid();
                    Eegeo_GL(m_func(T_glEnum, paramA));
                    return true;
                }
                return false;
            }
            
            inline bool TrySet(const GLStateEnumFunc1& stateToSet)
            {
                if(stateToSet.IsStateValid())
                {
                    return TrySet(stateToSet.m_paramA);
                }
                
                Eegeo_ASSERT(IsStateValid() == false, "Can't set a valid from an invalid state");
                return false;
            }
            
            inline bool TrySetIfNotAttempted(const GLStateEnumFunc1& stateToSet)
            {
                if(!TrySetAttempted())
                {
                    return TrySet(stateToSet);
                }

                return false;
            }
            
        private:
            void (EEGEO_GL_API_CALL *m_func)(GLenum, T_paramA);
            T_paramA m_paramA;
        };
    }
}

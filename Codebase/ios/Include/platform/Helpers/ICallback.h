// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


namespace Eegeo
{
    namespace Helpers
    {
        class ICallback0
        {
        public:
            virtual ~ICallback0() {}
            virtual void operator()() const = 0;
        };
        
        template <typename TCallbackContext>
        class TCallback0 : public ICallback0
        {
        public:
            typedef void (TCallbackContext::*TCallTarget)();
            
            TCallback0(TCallbackContext* context, TCallTarget callback)
            : m_callback(callback)
            , m_pContext(context)
            {
            }
            
            virtual void operator()() const
            {
                (*m_pContext.*m_callback)();
            }
        private:
            TCallTarget m_callback;
            TCallbackContext* m_pContext;
        };
        
        template <typename T>
        class ICallback1
        {
        public:
            virtual ~ICallback1() {}
            virtual void operator()(T& item) const = 0;
        };
        
        template <typename TCallbackContext, typename TItem>
        class TCallback1 : public ICallback1<TItem>
        {
        public:
            typedef void (TCallbackContext::*TCallTarget)(TItem& item);
            
            TCallback1(TCallbackContext* context, TCallTarget callback)
            : m_callback(callback)
            , m_pContext(context)
            {
            }
            
            virtual ~TCallback1() { }

            virtual void operator()(TItem& item) const
            {
                (*m_pContext.*m_callback)(item);
            }
        private:
            TCallTarget m_callback;
            TCallbackContext* m_pContext;
        };
        
        template <typename TItem1, typename TItem2>
        class ICallback2
        {
        public:
            virtual ~ICallback2() {}
            virtual void operator()(TItem1& item1, TItem2& item2) const = 0;
        };
        
        template <typename TCallbackContext, typename TItem1, typename TItem2>
        class TCallback2 : public ICallback2<TItem1, TItem2>
        {
        public:
            typedef void (TCallbackContext::*TCallTarget)(TItem1& item1, TItem2& item2);
            
            TCallback2(TCallbackContext* context, TCallTarget callback)
            : m_callback(callback)
            , m_pContext(context)
            {
            }
            
            virtual ~TCallback2() { }

            virtual void operator()(TItem1& item1, TItem2& item2) const
            {
                (*m_pContext.*m_callback)(item1, item2);
            }
        private:
            TCallTarget m_callback;
            TCallbackContext* m_pContext;
        };
        
        template <typename TItem1, typename TItem2, typename TItem3>
        class ICallback3
        {
        public:
            virtual ~ICallback3() {}
            virtual void operator()(TItem1& item1, TItem2& item2, TItem3& item3) const = 0;
        };
        
        template <typename TCallbackContext, typename TItem1, typename TItem2, typename TItem3>
        class TCallback3 : public ICallback3<TItem1, TItem2, TItem3>
        {
        public:
            typedef void (TCallbackContext::*TCallTarget)(TItem1& item1, TItem2& item2, TItem3& item3);
            
            TCallback3(TCallbackContext* context, TCallTarget callback)
            : m_callback(callback)
            , m_pContext(context)
            {
            }
            
            virtual ~TCallback3() { }
            
            virtual void operator()(TItem1& item1, TItem2& item2, TItem3& item3) const
            {
                (*m_pContext.*m_callback)(item1, item2, item3);
            }
        private:
            TCallTarget m_callback;
            TCallbackContext* m_pContext;
        };

    }
}

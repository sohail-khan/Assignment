#pragma once

#include "Types.h"
#include "Helpers.h"
#include "WorkItem.h"

namespace Eegeo
{
    namespace iOS
    {
        class iOSLegacyCacheClearWorkItem: public Concurrency::Tasks::WorkItem
        {
        public:
            
            iOSLegacyCacheClearWorkItem(Helpers::IFileIO& fileIO);
            
        protected:

            void DoWork();

            void DoFinalizeOnMainThread();
            
        private:
            
            Helpers::IFileIO& m_fileIO;

        };
    }
}
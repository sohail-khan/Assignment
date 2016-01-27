// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Command.h"
#include "Commands.h"
#include "DebugRenderer.h"

namespace Eegeo
{
    namespace Debug
    {
        namespace Commands
        {
            namespace Rendering
            {
                class DrawDebugLineCommand : public Command
                {
                public:
                    
                    DrawDebugLineCommand(DebugRendering::DebugRenderer& debugRenderer);
                    
                    bool TryExecute(const std::vector<std::string>& arguments,
                                    const ICommandTerminalOutput& commandTerminal) const;
                    
                private:
                    
                    DebugRendering::DebugRenderer& m_debugRenderer;
                };
            }
        }
    }
}
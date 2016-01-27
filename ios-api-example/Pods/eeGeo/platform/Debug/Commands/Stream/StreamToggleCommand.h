// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Command.h"
#include "Commands.h"
#include "StreamingController.h"

namespace Eegeo
{
    namespace Debug
    {
        namespace Commands
        {
            namespace Stream
            {
                class StreamToggleCommand :	public Command
                {
                public:
                    StreamToggleCommand(Streaming::StreamingController& streamingController);

                    bool TryExecute(
                            const std::vector<std::string>& arguments,
                            const ICommandTerminalOutput& commandTerminal) const;
                private:
                    Streaming::StreamingController& m_streamingController;
                };
            }
        }
    }
}
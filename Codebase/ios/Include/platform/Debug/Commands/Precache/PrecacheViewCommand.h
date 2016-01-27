// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Command.h"
#include "Commands.h"
#include "StreamingVolumeController.h"
#include "PrecacheService.h"
#include "IFrustumVolumeProvider.h"

namespace Eegeo
{
    namespace Debug
    {
        namespace Commands
        {
            namespace Precache
            {
                class PrecacheViewCommand : public Command
                {
                public:
                    PrecacheViewCommand(Eegeo::Web::PrecacheService& precacheService,
                                        Eegeo::Streaming::IFrustumVolumeProvider& frustumVolumeProvider);

                    bool TryExecute(
                            const std::vector<std::string>& arguments,
                            const ICommandTerminalOutput& commandTerminal) const;
                private:
                    Eegeo::Web::PrecacheService& m_precacheService;
                    Eegeo::Streaming::IFrustumVolumeProvider& m_frustumVolumeProvider;
                };
            }
        }
    }
}

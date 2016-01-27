// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    class IEegeoErrorHandler
    {
    public:
        virtual ~IEegeoErrorHandler(){};
        
        /*!
         * \brief Handle bad API key.
         *
         *  This method is called when the API token given to the
         *  EegeoWorld class is invalid or has been revoked.
         */
        virtual void HandleFailureToProvideWorkingApiKey()
        {
        }
        
        /*!
         * \brief Handle resource download failure.
         *
         *  This method is called when the SDK cannot download critical
         *  resources that it needs to function.
         *  This could occur if no network connection is available and
         *  no cached resourvces exist on the device.
         *  Note, on first run the SDK will cache downloaded critical
         *  resources for future use.
         */
        virtual void HandleFailureToDownloadBootstrapResources()
        {
        }
        
        /*!
         * \brief Handle warning of no internet connectivity
         *
         *  This method is called when the SDK has tested the strength of
         *  the internet connection and found that no net connection is
         *  available.  The SDK can run without one in a reduced manner,
         *  providing the Bootstrap Resources have previously been cached.
         *  Otherwise you will recieve the HandleFailureToDownloadBootstrapResources
         *  error.
         */
        virtual void HandleNoConnectivityWarning()
        {
        }
        
        /*!
         * \brief Handle invalid internet connectivity failure.
         *
         *  This method is called when the SDK has tested the strength of
         *  the internet connection and found that while a net connection
         *  exists, it is functioning abnormally.  This can be due to
         *  proxy servers or unauthorized captive wi-fi portals. The SDK
         *  should not run in this state.
         */
        virtual void HandleInvalidConnectivityError()
        {
        }
    };
}

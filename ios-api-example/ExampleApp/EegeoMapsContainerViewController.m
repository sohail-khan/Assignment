// Copyright eeGeo Ltd (2012-2014), All Rights Reserved





#import "EegeoMapsContainerViewController.h"
#import "EGApi.h"
#import "EegeoCustomAnnotationView.h"

@interface EegeoMapsContainerViewController () <CLLocationManagerDelegate>
@property (strong, nonatomic) CLLocationManager *locationManager;
@end

@interface EegeoMapsContainerViewController () <EGMapDelegate>
@property (strong, nonatomic) id<EGMapApi> eegeoMapApi;
@end

@interface EegeoMapsContainerViewController ()
@property (strong, nonatomic) EGMapView* eegeoMapView;

@property (strong, nonatomic) id<EGPrecacheOperation> precacheOperation;
@property (strong, nonatomic) id<EGPolygon> geoFencePoly;

@property (strong, nonatomic) EGPointAnnotation* marker1;
@property (strong, nonatomic) EGPointAnnotation* marker2;
@property (strong, nonatomic) EGPointAnnotation* marker3;
@property (strong, nonatomic) EGPointAnnotation* marker4;
@property (strong, nonatomic) EGPointAnnotation* marker5;
@property (strong, nonatomic) EGPointAnnotation* marker6;
@property (strong, nonatomic) EGPointAnnotation* marker7;



@property (strong, nonatomic) NSTimer* timer;
@end

@implementation EegeoMapsContainerViewController
{
    int m_mapThemeCursor;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.eegeoMapApi = nil;
    self.timer = nil;
    self.precacheOperation = nil;
    self.geoFencePoly = nil;
    self.marker1 = nil;
    self.marker2 = nil;
    self.marker3 = nil;
    self.marker4 = nil;
    self.marker5 = nil;
    self.marker6 = nil;
    self.marker7 = nil;

    
    m_mapThemeCursor = 0;
    
    self.eegeoMapView = [[[EGMapView alloc] initWithFrame:self.view.bounds] autorelease];
    self.eegeoMapView.eegeoMapDelegate = self;
    self.eegeoMapView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    
    [self.view insertSubview:self.eegeoMapView atIndex:0];
    
    self.locationManager = [[[CLLocationManager alloc] init] autorelease];
}

-(void) viewWillAppear:(BOOL)animated
{
    [super viewWillAppear :animated];
    
    self.locationManager.delegate = self;
    
    if ([self.locationManager respondsToSelector:@selector(requestWhenInUseAuthorization)]) {
        [self.locationManager requestWhenInUseAuthorization];
    }
    
    [self.locationManager startUpdatingLocation];
}

- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:(BOOL)animated];
    
    if(self.precacheOperation != nil)
    {
        [self.precacheOperation cancel];
        self.precacheOperation = nil;
    }
    
    self.locationManager.delegate = nil;
    [self.locationManager stopUpdatingLocation];
    self.locationManager = nil;
    
    [self.eegeoMapApi removeAnnotation: self.marker1];
    [self.eegeoMapApi removeAnnotation: self.marker2];
    [self.eegeoMapApi removeAnnotation: self.marker3];
    [self.eegeoMapApi removeAnnotation: self.marker4];
    [self.eegeoMapApi removeAnnotation: self.marker5];
    [self.eegeoMapApi removeAnnotation: self.marker6];
    [self.eegeoMapApi removeAnnotation: self.marker7];


    self.marker1 = nil;
    self.marker2 = nil;
    self.marker3 = nil;
    self.marker4 = nil;
    self.marker5 = nil;
    self.marker6 = nil;
    self.marker7 = nil;


    
    [self.eegeoMapApi removePolygon:self.geoFencePoly];
    self.geoFencePoly = nil;
    
    if(self.timer != nil)
    {
        [self.timer invalidate];
        self.timer = nil;
    }
    
    self.eegeoMapApi = nil;
    
    [self.eegeoMapView removeFromSuperview];
    self.eegeoMapView.eegeoMapDelegate = nil;
    self.eegeoMapView = nil;
}

- (void)eegeoMapReady:(id<EGMapApi>)api
{
    self.eegeoMapApi = api;
    [self handleMapAvailable];
    
    self.timer = [NSTimer scheduledTimerWithTimeInterval:10
                                                  target:self
                                                selector:@selector(cycleMapTheme)
                                                userInfo:nil
                                                 repeats:YES];
}

-(void)goHome
{
    if(self.eegeoMapApi != nil)
    {
        [self setLocation:YES];
    }
}

-(void)fitToDefaultBounds
{
    if(self.eegeoMapApi != nil)
    {
        [self setCoordinateBounds];
    }
}

- (void)handleMapAvailable
{
    [self setLocation:NO];
    [self addGeofencePolygon];
    [self addAnnotations];
    [self precacheBounds];
    [self cycleMapTheme];
}

- (void)cycleMapTheme
{
    EGMapTheme* mapTheme = nil;
    
    [self.eegeoMapApi setEnvironmentFlatten:false];
    
    switch(m_mapThemeCursor)
    {
        case 0:
            mapTheme = [[[EGMapTheme alloc] initWithSeason: EGMapThemeSeasonSummer
                                                   andTime: EGMapThemeTimeDay
                                                andWeather: EGMapThemeWeatherClear] autorelease];
            [self.geoFencePoly setColor:1.0f g:0.f b:0.f a:0.2f];
            break;
        case 1:
            mapTheme = [[[EGMapTheme alloc] initWithSeason: EGMapThemeSeasonSummer
                                                   andTime: EGMapThemeTimeNight
                                                andWeather: EGMapThemeWeatherClear] autorelease];
            [self.geoFencePoly setColor:0.9f g:0.9f b:0.9f a:0.3f];
            break;
        case 2:
            mapTheme = [[[EGMapTheme alloc] initWithSeason: EGMapThemeSeasonSummer
                                         andThemeStateName: @"MapMode"] autorelease];
            
            [self.eegeoMapApi setEnvironmentFlatten:true];
            [self.geoFencePoly setColor:0.1f g:0.1f b:0.1f a:0.3f];
            break;
    }
    
    [self.eegeoMapApi setMapTheme: mapTheme];
    
    m_mapThemeCursor = (m_mapThemeCursor + 1) % 3;
}

- (void)flattenEnvironment
{
    [self.eegeoMapApi setEnvironmentFlatten:false];
}

- (void)setLocation:(BOOL)animated
{
    [self.eegeoMapApi setCenterCoordinate:CLLocationCoordinate2DMake(37.793436, -122.398654)
                           distanceMetres:2000.0
                       orientationDegrees:0.f
                                 animated:animated];
}

-(void)setCoordinateBounds
{
    CLLocationCoordinate2D coordinates[] = {
        CLLocationCoordinate2DMake(37.797818, -122.407015),
        CLLocationCoordinate2DMake(37.798886, -122.398238),
        CLLocationCoordinate2DMake(37.798547, -122.397831),
        CLLocationCoordinate2DMake(37.795482, -122.396736),
        CLLocationCoordinate2DMake(37.794159, -122.395116),
        CLLocationCoordinate2DMake(37.786647, -122.404697)
    };
    NSUInteger numberOfCoordinates = sizeof(coordinates) / sizeof(CLLocationCoordinate2D);
    
    EGCoordinateBounds bounds = EGCoordinateBoundsFromCoordinatesMake(coordinates, numberOfCoordinates);
    
    [self.eegeoMapApi setVisibleCoordinateBounds:bounds animated:YES];
}

- (void)addGeofencePolygon
{
//    CLLocationCoordinate2D coordinates[] = {
//        CLLocationCoordinate2DMake(37.797818, -122.407015),
//        CLLocationCoordinate2DMake(37.798886, -122.398238),
//        CLLocationCoordinate2DMake(37.798547, -122.397831),
//        CLLocationCoordinate2DMake(37.795482, -122.396736),
//        CLLocationCoordinate2DMake(37.794159, -122.395116),
//        CLLocationCoordinate2DMake(37.786647, -122.404697)
//    };
    
    CLLocationCoordinate2D coordinates[] = {
        CLLocationCoordinate2DMake(37.791876, -122.410823),
        CLLocationCoordinate2DMake(37.791444, -122.414106),
        CLLocationCoordinate2DMake(37.792353, -122.414306),
        CLLocationCoordinate2DMake(37.79325, -122.414492),
        CLLocationCoordinate2DMake(37.793456, -122.412844),
        CLLocationCoordinate2DMake(37.793456, -122.412844)
    };
    NSUInteger numberOfCoordinates = sizeof(coordinates) / sizeof(CLLocationCoordinate2D);
    
    self.geoFencePoly = [self.eegeoMapApi polygonWithCoordinates:coordinates count:numberOfCoordinates];
    
    [self.geoFencePoly setColor:1.0f g:0.0f b:0.0f a:0.2f];
    [self.eegeoMapApi addPolygon:self.geoFencePoly];
}

- (void)addAnnotations
{
    self.marker1 = [[[EGPointAnnotation alloc] init] autorelease];
    self.marker1.coordinate = CLLocationCoordinate2DMake(37.791876, -122.410823);
    [self.eegeoMapApi addAnnotation:self.marker1];
    
    // Set data after adding Annotation to test KVO.
    self.marker1.title = @"California St & Mason St";
    self.marker1.subtitle = @"San Francisco, CA 94108, USA";
    
    self.marker2 = [[[EGPointAnnotation alloc] init] autorelease];
    self.marker2.coordinate = CLLocationCoordinate2DMake(37.791444, -122.414106);
    self.marker2.title = @"California St & Jones St";
    self.marker2.subtitle = @"San Francisco, CA 94109, USA";
    [self.eegeoMapApi addAnnotation:self.marker2];
    
    self.marker3 = [[[EGPointAnnotation alloc] init] autorelease];
    self.marker3.coordinate = CLLocationCoordinate2DMake(37.792353, -122.414306);
    self.marker3.title = @"Nob Hill, San Francisco";
    self.marker3.subtitle = @"CA, USA";
    [self.eegeoMapApi addAnnotation:self.marker3];
    
    
    
    self.marker4 = [[[EGPointAnnotation alloc] init] autorelease];
    self.marker4.coordinate = CLLocationCoordinate2DMake(37.79325, -122.414492);
    self.marker4.title = @"Clay St & Jones St";
    self.marker4.subtitle = @"San Francisco, CA 94109, USA";
    [self.eegeoMapApi addAnnotation:self.marker4];
    
    
    self.marker5 = [[[EGPointAnnotation alloc] init] autorelease];
    self.marker5.coordinate = CLLocationCoordinate2DMake(37.793456, -122.412844);
    self.marker5.title = @"Washington St & Taylor St";
    self.marker5.subtitle = @"San Francisco, CA 94108, USA";
    [self.eegeoMapApi addAnnotation:self.marker5];
    
    
    self.marker6 = [[[EGPointAnnotation alloc] init] autorelease];
    self.marker6.coordinate = CLLocationCoordinate2DMake(37.793655,-122.411227);
    self.marker6.title = @"Clay St & Mason St";
    self.marker6.subtitle = @"San Francisco, CA 94108, USA";
    [self.eegeoMapApi addAnnotation:self.marker6];
    
    
    self.marker7 = [[[EGPointAnnotation alloc] init] autorelease];
    self.marker7.coordinate = CLLocationCoordinate2DMake(37.794544, -122.41138);//,  g. ,
    self.marker7.title = @"Washington St & Mason St";
    self.marker7.subtitle = @"San Francisco, CA 94108, USA";
    [self.eegeoMapApi addAnnotation:self.marker7];

    
    // Test programmatic selection.
    //[self.eegeoMapApi selectAnnotation:self.marker1 animated:NO];
    //[self.eegeoMapApi selectAnnotation:self.marker2 animated:NO];
    //[self.eegeoMapApi selectAnnotation:self.marker3 animated:NO];
}

- (void)precacheBounds
{
//    EGCoordinateBounds bounds = EGCoordinateBoundsMake(CLLocationCoordinate2DMake(37.794771, -122.400929),
//                                                       CLLocationCoordinate2DMake(37.792440, -122.396369));
    
    
    EGCoordinateBounds bounds = EGCoordinateBoundsMake(CLLocationCoordinate2DMake(37.791876, -122.410823),CLLocationCoordinate2DMake(37.792353, -122.414306));

    
    id<EGPrecacheOperation> precacheCancelExample = [self.eegeoMapApi precacheMapDataInCoordinateBounds:bounds];
    
    [precacheCancelExample cancel];
    
    self.precacheOperation = [self.eegeoMapApi precacheMapDataInCoordinateBounds:bounds];
}

- (void)precacheOperationCompleted:(id<EGPrecacheOperation>)precacheOperation
{
    BOOL cancelled = [precacheOperation cancelled];
    BOOL completed = [precacheOperation completed];
    
    printf("%s\n", cancelled ? "Cancelled" : "Not cancelled");
    printf("%s\n", completed ? "Completed" : "Not completed");
    printf("Percent: %d\n", [precacheOperation percentComplete]);
    
    if(precacheOperation == self.precacheOperation)
    {
        self.precacheOperation = nil;
    }
}

- (EGAnnotationView*)viewForAnnotation:(id<EGAnnotation>)annotation
{
    // Custom view for marker one that always shows data, no callout as always showing data.
    /*if(annotation == self.marker1)
    {
        // XIB defined in app, code-behind extends EGAnnotationView.
        EegeoCustomAnnotationView* pCustomView = [[[NSBundle mainBundle]
                                                   loadNibNamed:@"EegeoCustomAnnotationView"
                                                   owner:self
                                                   options:nil] lastObject];
        
        pCustomView.canShowCallout = NO;
        
        // Manually (re)bind the annotation, intially nil for custom view.
        pCustomView.annotation = annotation;
        pCustomView.imageView.image = [UIImage imageNamed:@"custom_annotation_image"];
        
        pCustomView.centerOffset = CGPointMake(-pCustomView.frame.size.width * 0.5f,
                                               -pCustomView.frame.size.height);
        
        return pCustomView;
    }*/
    
    // For other pins use default view.
    return nil;
}

- (void)didSelectAnnotation:(id<EGAnnotation>)annotation
{
    // Add a nice left callout accessory.
    EGAnnotationView* view = [self.eegeoMapApi viewForAnnotation:annotation];
    view.leftCalloutAccessoryView = [UIButton buttonWithType:UIButtonTypeDetailDisclosure];
    
    printf("Selected annotation with title: %s\n", [[annotation title] UTF8String]);
}

- (void)didDeselectAnnotation:(id<EGAnnotation>)annotation
{
    printf("Deselected annotation with title: %s\n", [[annotation title] UTF8String]);
    
    // Remove the left callout accessory.
    EGAnnotationView* view = [self.eegeoMapApi viewForAnnotation:annotation];
    view.leftCalloutAccessoryView = nil;
}

- (BOOL)shouldUseEegeoPinTextureAnnotation:(id<EGAnnotation>)annotation eegeoPinTexturePageIndex:(NSInteger*)eegeoPinTexturePageIndex;
{
    // No pin for annotation 1 (with the custom view).
    if(annotation == self.marker1)
    {
        return YES;
    }
    
    // Specify annotation texture index for annotation 3.
    if(annotation == self.marker3)
    {
        *eegeoPinTexturePageIndex = 4;
    }
    
    // Use default value for other annotations.
    return YES;
}
@end



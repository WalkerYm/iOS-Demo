//
//  WYMInteractiveTransition.m
//  WYM_UIViewController_Demo
//
//  Created by WalkerYm on 2017/9/4.
//  Copyright © 2017年 WalkerYm. All rights reserved.
//

#import "WYMInteractiveTransition.h"

@interface WYMInteractiveTransition()

@property (nonatomic, assign) WYMInteractiveTransitionType type;
@property (nonatomic, assign) WYMInteractiveTransitionGestureDirection guestureDirection;

@property (nonatomic, strong) UIViewController *vc;

@end

@implementation WYMInteractiveTransition

+ (instancetype)wym_intertativeTransitionWithTransitionType:(WYMInteractiveTransitionType)type gestureDiraction:(WYMInteractiveTransitionGestureDirection)direction{


    return [[self alloc] initWithTransitionType:type gestureDiraction:direction];
}

- (instancetype)initWithTransitionType:(WYMInteractiveTransitionType)type gestureDiraction:(WYMInteractiveTransitionGestureDirection)direction{

    self = [super init];
    if (self) {
        _type = type;
        _guestureDirection = direction;
    }
    
    return self;
}

- (void)wym_addPanGestureForViewController:(UIViewController *)viewController{

    UIPanGestureRecognizer *pan = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(p_handleGesture:)];
    self.vc = viewController;
    [viewController.view addGestureRecognizer:pan];
}

- (void)p_handleGesture:(UIPanGestureRecognizer *)panGesture{

    CGFloat percent = 0.0;
    switch (_guestureDirection) {
        case WYMInteractiveTransitionGestureDirectionLeft:
        {
            CGFloat transitionX = -[panGesture translationInView:panGesture.view].x;
            percent = transitionX / panGesture.view.frame.size.width;
            break;
            
        }
        case WYMInteractiveTransitionGestureDirectionRight:
        {
            CGFloat transitionX = [panGesture translationInView:panGesture.view].x;
            percent = transitionX / panGesture.view.frame.size.width;
            break;
            
        }
            
        case WYMInteractiveTransitionGestureDirectionUp:
        {
            CGFloat transitionX = -[panGesture translationInView:panGesture.view].y;
            
            percent = transitionX / panGesture.view.frame.size.width;
            NSLog(@"%lf, %lf, %lf", transitionX, panGesture.view.frame.size.width, percent);
            break;
            
        }
        case WYMInteractiveTransitionGestureDirectionDown:
        {
            CGFloat transitionX = [panGesture translationInView:panGesture.view].y;
            percent = transitionX / panGesture.view.frame.size.width;
            break;
            
        }
    }
    
    switch (panGesture.state) {
        case UIGestureRecognizerStateBegan:
            self.interation = YES;
         
                [self startGesture];
          
            
            break;
            
       case UIGestureRecognizerStateChanged:
        {
            if (percent < 1) {
                [self updateInteractiveTransition:percent];
            } else {
            
                [self updateInteractiveTransition:1];
            }
        
            break;
        }
            
        case UIGestureRecognizerStateEnded:
        {
            self.interation = NO;
            if (percent > 0.5) {
                [self finishInteractiveTransition];
            }else{
                [self cancelInteractiveTransition];
            }
        }
        default:
            break;
    }

}

- (void)startGesture{
    switch (_type) {
        case XWInteractiveTransitionTypePresent:{
            if (_presnetConfig) {
                _presnetConfig();
            }
        }
            break;
            
        case XWInteractiveTransitionTypeDismiss:
            [_vc dismissViewControllerAnimated:YES completion:nil];
            break;
        case XWInteractiveTransitionTypePush:{
            if (_pushConfig) {
                _pushConfig();
            }
        }
            break;
        case XWInteractiveTransitionTypePop:
            [_vc.navigationController popViewControllerAnimated:YES];
            break;
    }
}


@end

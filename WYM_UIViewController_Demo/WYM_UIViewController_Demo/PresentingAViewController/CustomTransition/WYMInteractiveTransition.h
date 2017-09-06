//
//  WYMInteractiveTransition.h
//  WYM_UIViewController_Demo
//
//  Created by WalkerYm on 2017/9/4.
//  Copyright © 2017年 WalkerYm. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <UIKit/UIKit.h>


typedef void(^GestureConifg) ();

typedef NS_ENUM(NSUInteger, WYMInteractiveTransitionGestureDirection) {

    WYMInteractiveTransitionGestureDirectionLeft = 0,
    WYMInteractiveTransitionGestureDirectionRight,
    WYMInteractiveTransitionGestureDirectionUp,
    WYMInteractiveTransitionGestureDirectionDown
};


typedef NS_ENUM(NSUInteger, WYMInteractiveTransitionType) {//手势控制哪种转场
    XWInteractiveTransitionTypePresent = 0,
    XWInteractiveTransitionTypeDismiss,
    XWInteractiveTransitionTypePush,
    XWInteractiveTransitionTypePop,
};



@interface WYMInteractiveTransition : UIPercentDrivenInteractiveTransition

@property (nonatomic, assign) BOOL interation;
@property (nonatomic, copy) GestureConifg presnetConfig;
@property (nonatomic, copy) GestureConifg pushConfig;

+ (instancetype)wym_intertativeTransitionWithTransitionType:(WYMInteractiveTransitionType)type gestureDiraction:(WYMInteractiveTransitionGestureDirection)direction;

- (instancetype)initWithTransitionType:(WYMInteractiveTransitionType)type gestureDiraction:(WYMInteractiveTransitionGestureDirection)direction;

- (void)wym_addPanGestureForViewController:(UIViewController *)viewController;

@end

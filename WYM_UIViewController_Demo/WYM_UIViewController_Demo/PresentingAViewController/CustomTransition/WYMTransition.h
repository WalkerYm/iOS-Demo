//
//  WYMTransition.h
//  WYM_UIViewController_Demo
//
//  Created by WalkerYm on 2017/9/4.
//  Copyright © 2017年 WalkerYm. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, WYMTransitonType) {
    
    WYMTransitonTypePresent = 0,
    WYMTransitonTypeDismiss
};

@interface WYMTransition : NSObject<UIViewControllerAnimatedTransitioning>

+ (instancetype)wym_transitionWithTransitionType:(WYMTransitonType)type;
- (instancetype)initWithTransitionType:(WYMTransitonType)type;

@end

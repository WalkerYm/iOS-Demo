//
//  WYMPresentedVC.h
//  WYM_UIViewController_Demo
//
//  Created by WalkerYm on 2017/9/4.
//  Copyright © 2017年 WalkerYm. All rights reserved.
//

#import <UIKit/UIKit.h>

@class WYMPresentedVC;

@protocol WYMPresentedVCDataSource <NSObject>

- (id<UIViewControllerInteractiveTransitioning>)interactiveTransitionForPresent;

@end

@interface WYMPresentedVC : UIViewController


@property (nonatomic, assign) id<WYMPresentedVCDataSource> dataSource;


@end

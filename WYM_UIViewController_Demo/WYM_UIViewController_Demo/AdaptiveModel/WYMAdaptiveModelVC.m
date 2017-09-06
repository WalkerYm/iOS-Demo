//
//  WYMAdaptiveModelVC.m
//  WYM_UIViewController_Demo
//
//  Created by WalkerYm on 2017/9/5.
//  Copyright © 2017年 WalkerYm. All rights reserved.
//

#import "WYMAdaptiveModelVC.h"

@interface WYMAdaptiveModelVC ()

@end

@implementation WYMAdaptiveModelVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
}

- (void)willTransitionToTraitCollection:(UITraitCollection *)newCollection withTransitionCoordinator:(id<UIViewControllerTransitionCoordinator>)coordinator{
    NSLog(@"改变 traint：%@", newCollection);
    
}

- (void)traitCollectionDidChange:(UITraitCollection *)previousTraitCollection{

    NSLog(@"以前 traint：%@", previousTraitCollection);
    
    
    /** 6s 竖屏
     <UITraitCollection: 0x6000000c6c10; 
     _UITraitNameUserInterfaceIdiom = Phone, 
     _UITraitNameDisplayScale = 2.000000, 
     _UITraitNameDisplayGamut = sRGB, 
     _UITraitNameHorizontalSizeClass = Compact, 
     _UITraitNameVerticalSizeClass = Regular, 
     _UITraitNameTouchLevel = 0, 
     _UITraitNameInteractionModel = 1, 
     _UITraitNameUserInterfaceStyle = 1, 
     _UITraitNameLayoutDirection = 0, 
     _UITraitNameForceTouchCapability = 2,
     _UITraitNamePreferredContentSizeCategory = UICTContentSizeCategoryL>
     **/
    
    /** 6s 横屏
     traint：<UITraitCollection: 0x6000000c7770; 
     _UITraitNameUserInterfaceIdiom = Phone, 
     _UITraitNameDisplayScale = 2.000000, 
     _UITraitNameDisplayGamut = sRGB, 
     _UITraitNameHorizontalSizeClass = Compact, 
     _UITraitNameVerticalSizeClass = Compact, 
     _UITraitNameTouchLevel = 0, 
     _UITraitNameInteractionModel = 1, 
     _UITraitNameUserInterfaceStyle = 1, 
     _UITraitNameLayoutDirection = 0, 
     _UITraitNameForceTouchCapability = 2, 
     _UITraitNamePreferredContentSizeCategory = UICTContentSizeCategoryL>
     */
    
    /** 6s plus 竖屏
     traint：<UITraitCollection: 0x1740cf260; 
     _UITraitNameUserInterfaceIdiom = Phone, 
     _UITraitNameDisplayScale = 3.000000, 
     _UITraitNameDisplayGamut = sRGB, 
     _UITraitNameHorizontalSizeClass = Compact, 
     _UITraitNameVerticalSizeClass = Regular, 
     _UITraitNameTouchLevel = 0, 
     _UITraitNameInteractionModel = 1, 
     _UITraitNameUserInterfaceStyle = 1, 
     _UITraitNameLayoutDirection = 0, 
     _UITraitNameForceTouchCapability = 2, 
     _UITraitNamePreferredContentSizeCategory = UICTContentSizeCategoryL>
     */
    
    /** 6s plus 横屏
   traint：<UITraitCollection: 0x1740cfab0; 
     _UITraitNameUserInterfaceIdiom = Phone, 
     _UITraitNameDisplayScale = 3.000000, 
     _UITraitNameDisplayGamut = sRGB, 
     _UITraitNameHorizontalSizeClass = Regular,
     _UITraitNameVerticalSizeClass = Compact, 
     _UITraitNameTouchLevel = 0, 
     _UITraitNameInteractionModel = 1, 
     _UITraitNameUserInterfaceStyle = 1, 
     _UITraitNameLayoutDirection = 0, 
     _UITraitNameForceTouchCapability = 2, _UITraitNamePreferredContentSizeCategory = UICTContentSizeCategoryL>
     */
    
}

- (void)viewWillTransitionToSize:(CGSize)size withTransitionCoordinator:(id<UIViewControllerTransitionCoordinator>)coordinator{

    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end

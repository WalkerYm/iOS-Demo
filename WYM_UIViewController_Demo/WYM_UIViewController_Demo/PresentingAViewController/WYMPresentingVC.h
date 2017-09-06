//
//  WYMPresentingVC.h
//  WYM_UIViewController_Demo
//
//  Created by WalkerYm on 2017/9/4.
//  Copyright © 2017年 WalkerYm. All rights reserved.
//

#import <UIKit/UIKit.h>

/** Presenting a View Controller
 
 1. Presentation Style 展示样式：
    1）Full-Screen Presentation Styles 全屏展示样式；UIModalPresentationFullScreen 和 UIModalPresentationOverFullScreen
    2）The Popover Style 弹出样式; UIModalPresentationPopover
    3）The Current Context Styles；UIModalPresetationCurrentContext
    4）自定义展示样式：UIModalPresentationCustom
 
 
 2. Transition Style 切换样式：
 
 3. 两种显示视图控制器的方法：
    1）showViewController：sender  或 showDetailViewController： sender：
    2）prensentViewController：animated：completion：
    3）使用 segue；
 
 4. 特别注意：
    1）UIMoalPresentationPopover 需要额外的配置才能呈现。
    2）dismiss Presented View Controller；
    3）不同 Storyboard 之间的控制器跳转。
 
 
 */


@interface WYMPresentingVC : UIViewController

@end

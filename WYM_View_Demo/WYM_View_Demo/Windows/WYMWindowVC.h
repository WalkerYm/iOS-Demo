//
//  WYMWindowVC.h
//  WYM_View_Demo
//
//  Created by WalkerYm on 2017/9/6.
//  Copyright © 2017年 WalkerYm. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface WYMWindowVC : UIViewController

@end


/** Window 类的责任
 
 - 包含应用程序的可见内容；
 - 在触摸事件传递给中起关键作用；
 - 与视图控制器协调 App 屏幕方向更改；
 
 */

/**一、涉及 Windows 的任务：
 - 使用窗口对象转换点的坐标，如窗口坐标系中提供了值，将其转换为某个特定视图的坐标系；
 - 使用窗口通知来跟踪相关窗口的更改；
 
 */

/** 二、创建并配置窗口
 1. 使用 IB 创建窗口
 2. 使用代码创建窗口：
 3. 往窗口中添加内容：
 4. 改变窗口的显示等级：windowLevel 属性
 */

/**三、监听窗口更改
 使用一下通知：
 UIWindowDidBecomeVisibleNotification
 UIWindowDidBecomeHiddenNotification
 UIWindowDidBecomeKeyNotification
 UIWindowDidResignKeyNotification

 */

/** 四、在外部屏幕显示内容
 
 */




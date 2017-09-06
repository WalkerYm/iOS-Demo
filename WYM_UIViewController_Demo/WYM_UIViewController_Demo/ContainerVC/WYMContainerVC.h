//
//  WYMContainerVC.h
//  WYM_UIViewController_Demo
//
//  Created by WalkerYm on 2017/9/4.
//  Copyright © 2017年 WalkerYm. All rights reserved.
//

#import <UIKit/UIKit.h>


/** 容器视图：容器视图控制器从其他视图控制器获取器内容的一部分。
 *
 *
 
 设计容器视图需要考虑的八个问题：
 1. 容器的作用是什么？子控制器扮演什么角色？
 2. 同时显示多少个子控制器？
 3. 兄弟视图控制器之间的关系（如果有）是什么？
 4. 如何将子视图控制器添加到容器中或从容器中移除？
 5. 子视图控制器的大小或位置可以改变吗？ 这些变化在什么条件下发生？
 6. 容器是否提供了自己的装饰或导航相关的视图？
 7. 容器控制器和子视图控制器之间需要什么样的沟通？ 容器需要向其子级报告除 UIViewController 类定义的标准以外的特定事件吗？
 8. 容器的外观能否以不同的方式进行配置？ 如果是这样，怎么办？
 *
 *
 */

@interface WYMContainerVC : UIViewController

@end

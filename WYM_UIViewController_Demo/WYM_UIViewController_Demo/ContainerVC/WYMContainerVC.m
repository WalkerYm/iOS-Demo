//
//  WYMContainerVC.m
//  WYM_UIViewController_Demo
//
//  Created by WalkerYm on 2017/9/4.
//  Copyright © 2017年 WalkerYm. All rights reserved.
//

#import "WYMContainerVC.h"
#import "WYMFirstVC.h"
#import "WYMSecondVC.h"

@interface WYMContainerVC ()

@property (nonatomic ,strong) WYMFirstVC *firstVC;
@property (nonatomic, strong) WYMSecondVC *secondVC;

@end

@implementation WYMContainerVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    self.view.backgroundColor = [UIColor redColor];
    self.title = NSStringFromClass([WYMContainerVC class]);
    
    _firstVC = [WYMFirstVC new];
    [self p_setUpRelationshipWithSubVC:_firstVC];
}

- (void)viewWillAppear:(BOOL)animated{

    [super viewWillAppear:animated];
    
    [self.firstVC beginAppearanceTransition:YES animated:animated];
     [self.secondVC beginAppearanceTransition:YES animated:animated];
}

-(void) viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];

    [self.firstVC endAppearanceTransition];
    [self.secondVC endAppearanceTransition];
}

-(void) viewWillDisappear:(BOOL)animated {
    
    [super viewWillDisappear:animated];
    [self.firstVC beginAppearanceTransition: NO animated: animated];
    [self.secondVC beginAppearanceTransition: NO animated: animated];
}

-(void) viewDidDisappear:(BOOL)animated {
    
    [super viewDidDisappear:animated];
    [self.secondVC endAppearanceTransition];
    [self.firstVC endAppearanceTransition];
}


#pragma mark - 建立父子关系
- (void)p_setUpRelationshipWithSubVC:(UIViewController *)subVC{


    /**
     1. 调用容器视图控制器的 addChildViewController：方法。
        此方法告诉UIKit您的容器视图控制器正在管理子视图控制器的视图。
     2. 将小孩的根视图添加到容器的视图层次结构中。
     在此过程中，请始终记住设置小孩框架的大小和位置。
     3. 添加用于管理子视图的大小和位置的任何约束。
     4. 调用子视图控制器的 didMoveToParentViewController：方法。
     */
    
    [self addChildViewController:subVC];
    subVC.view.frame = CGRectMake(100, 100, 100, 100);
    [self.view addSubview:subVC.view];
    [subVC didMoveToParentViewController:self];
}

#pragma mark - 删除父子关系
- (void)p_removeRelationshipWithSubVC:(UIViewController *)subVC{

    
    /**
     1. 调用子视图控制器的 willMoveToParentViewController：方法，值为nil。
     2. 删除使用的子视图控制器的根视图配置的任何限制。
     3. 从容器的视图层次结构中删除孩子的根视图。
     4. 调用孩子的 removeFromParentViewController 方法来确定父子关系的结束。
     */
    
    [subVC willMoveToParentViewController:nil];
    [subVC.view removeFromSuperview];
    [subVC removeFromParentViewController];
}


#pragma mark - 在两个子视图控制器中切换
- (void)p_transitionFromOldVC:(UIViewController *)oldVC toNewVC:(UIViewController *)newVC{

    [oldVC willMoveToParentViewController:nil];
    [self addChildViewController:newVC];
    
    newVC.view.frame = CGRectMake(0, 0, 0, 0);
    CGRect endFrame = CGRectMake(0, 0, 0, 0);
    
    [self transitionFromViewController:oldVC toViewController:newVC duration:1 options:0 animations:^{
        newVC.view.frame = self.view.frame;
        oldVC.view.frame = endFrame;
    } completion:^(BOOL finished) {
        [oldVC removeFromParentViewController];
        [newVC didMoveToParentViewController:self];
    }];
    
    /**
     transitionFromViewController：toViewController：duration：options：animations：completion：方法自动更新容器的视图层次结构，因此您不需要自己添加和删除视图。
     */
}


- (UIViewController *)childViewControllerForStatusBarStyle{

    return self.firstVC;
}

- (UIViewController *)childViewControllerForStatusBarHidden{

    return self.firstVC;
}


//
//
//- (BOOL)shouldAutomaticallyForwardAppearanceMethods{
//
//    return NO;
//}


- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event{

    
//    [self p_removeRelationshipWithSubVC:self.firstVC];
    if (!_secondVC) {
        _secondVC = [WYMSecondVC new];
        [self p_transitionFromOldVC:_firstVC toNewVC:_secondVC];

    }
    
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

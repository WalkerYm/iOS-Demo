
//
//  WYMPresentVC.m
//  WYM_UIViewController_Demo
//
//  Created by WalkerYm on 2017/9/4.
//  Copyright © 2017年 WalkerYm. All rights reserved.
//

#import "WYMPresentVC.h"
#import "WYMPresentedVC.h"

#import "WYMInteractiveTransition.h"

@interface WYMPresentVC ()<WYMPresentedVCDataSource>

@property (nonatomic, strong)  WYMInteractiveTransition *transition;

@end

@implementation WYMPresentVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    
    self.title = NSStringFromClass(self.class);
    
    _transition = [WYMInteractiveTransition wym_intertativeTransitionWithTransitionType:XWInteractiveTransitionTypePresent gestureDiraction:WYMInteractiveTransitionGestureDirectionUp];
    [_transition wym_addPanGestureForViewController:self.navigationController];
    typeof(self)weakSelf = self;
    _transition.presnetConfig = ^{
        
        [weakSelf clickNextBtn:nil];
    };
}

- (IBAction)clickNextBtn:(id)sender {
    
    WYMPresentedVC *presentedVC = [WYMPresentedVC new];
    presentedVC.dataSource = self;
    [self presentViewController:presentedVC animated:YES completion:nil];
}



#pragma mark - WYMPresentedVCDataSource

- (id<UIViewControllerInteractiveTransitioning>)interactiveTransitionForPresent{

   
    
    return self.transition;
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

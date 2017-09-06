//
//  WYMFistPresentationVC.m
//  WYM_UIViewController_Demo
//
//  Created by WalkerYm on 2017/9/5.
//  Copyright © 2017年 WalkerYm. All rights reserved.
//

#import "WYMFistPresentationVC.h"
#import "WYMSecondPresentationVC.h"
#import "WYMPresentationController.h"

@interface WYMFistPresentationVC ()

@end

@implementation WYMFistPresentationVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    
    self.title = NSStringFromClass(self.class);
    
}
- (IBAction)clickToSecondVCBtn:(id)sender {
    
    WYMSecondPresentationVC *secondVC = [WYMSecondPresentationVC new];
    
    
    WYMPresentationController *presentation = [[WYMPresentationController alloc] initWithPresentedViewController:secondVC presentingViewController:self];
    
//    AAPLCustomPresentationController *presentation = [[AAPLCustomPresentationController alloc] initWithPresentedViewController:secondVC presentingViewController:self];
//    secondVC.modalPresentationStyle = UIModalPresentationCustom;
    secondVC.transitioningDelegate = presentation;
    [self presentViewController:secondVC animated:YES completion:nil];
    

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

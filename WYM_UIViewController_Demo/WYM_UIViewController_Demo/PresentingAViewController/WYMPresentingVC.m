//
//  WYMPresentingVC.m
//  WYM_UIViewController_Demo
//
//  Created by WalkerYm on 2017/9/4.
//  Copyright © 2017年 WalkerYm. All rights reserved.
//

#import "WYMPresentingVC.h"

#import "WYMFirstSegueVC.h"

@interface WYMPresentingVC ()

@end

@implementation WYMPresentingVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    self.title = NSStringFromClass(self.class);
    
}
- (IBAction)clickSegueBtn:(id)sender {
    
    UIStoryboard *sb = [UIStoryboard storyboardWithName:@"segue" bundle:[NSBundle mainBundle]];
    WYMFirstSegueVC *firstVC = [sb instantiateViewControllerWithIdentifier:NSStringFromClass([WYMFirstSegueVC class])];
    [self.navigationController pushViewController:firstVC animated:YES];
    
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

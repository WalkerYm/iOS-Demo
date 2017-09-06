//
//  WYMSecondPresentationVC.m
//  WYM_UIViewController_Demo
//
//  Created by WalkerYm on 2017/9/5.
//  Copyright © 2017年 WalkerYm. All rights reserved.
//

#import "WYMSecondPresentationVC.h"

@interface WYMSecondPresentationVC ()

@end

@implementation WYMSecondPresentationVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    self.title = NSStringFromClass(self.class);
//    self.view.backgroundColor = [UIColor yellowColor];
    
    
    self.preferredContentSize = CGSizeMake(self.view.bounds.size.width, 270);
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

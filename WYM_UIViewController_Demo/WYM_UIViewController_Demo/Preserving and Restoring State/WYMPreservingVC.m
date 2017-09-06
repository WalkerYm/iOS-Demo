//
//  WYMPreservingVC.m
//  WYM_UIViewController_Demo
//
//  Created by WalkerYm on 2017/9/4.
//  Copyright © 2017年 WalkerYm. All rights reserved.
//

#import "WYMPreservingVC.h"
#import "WYMDetailVC.h"


static NSString * const kReusableCellIndentifier = @"cell";

@interface WYMPreservingVC ()<UITableViewDelegate, UITableViewDataSource>


@property (weak, nonatomic) IBOutlet UITableView *tableView;

@property (nonatomic, strong) NSArray *dataArray;


@end

@implementation WYMPreservingVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    
    [self p_initTableView];
}

- (void)p_initTableView{
    
    
    self.tableView.delegate = self;
    self.tableView.dataSource = self;
    [self.tableView setTableFooterView:[[UIView alloc] initWithFrame:CGRectZero]];
    
    self.automaticallyAdjustsScrollViewInsets = NO;
    self.title = @"UIViewController";
    self.restorationIdentifier = NSStringFromClass(self.class);
    self.tableView.restorationIdentifier = @"tableView";
}


#pragma mark - TableView Delegate
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    
    return self.dataArray.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:kReusableCellIndentifier];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:kReusableCellIndentifier];
    }
    
    cell.textLabel.text = self.dataArray[indexPath.row];
    
    return cell;
}


- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    
    
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    WYMDetailVC *subVC = [[WYMDetailVC alloc] init];
    subVC.showText = self.dataArray[indexPath.row];
    [self.navigationController pushViewController:subVC animated:YES];
}



#pragma mark - 懒加载
- (NSArray *)dataArray{
    
    if (!_dataArray) {
        _dataArray = @[@"测试1", @"测试2", @"测试3", @"测试4", @"测试5", @"测试6", @"测试7", @"测试8", @"测试9", @"测试10", @"测试11", @"测试12", @"测试1", @"测试2", @"测试3", @"测试4", @"测试5", @"测试6", @"测试7", @"测试8", @"测试9", @"测试10", @"测试11", @"测试12"];
    }
    
    return _dataArray;
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

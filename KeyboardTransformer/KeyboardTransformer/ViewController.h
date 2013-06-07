//
//  ViewController.h
//  KeyboardTransformer
//
//  Created by Administrator on 2013-01-09.
//  Copyright (c) 2013 Administrator. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController{
    UITextField *inputTextField;
    UILabel *keyboardLabel;
    NSMutableArray *currentKeyboard;
}

@property (nonatomic, retain) IBOutlet UITextField *inputTextField;
@property (nonatomic, retain) IBOutlet UILabel *keyboardLabel;

@property (nonatomic, retain) NSMutableArray *currentKeyboard;


- (IBAction)transform:(id)sender;
- (void)resetKeyboard:(NSString *)inputString;
- (BOOL)checkvalidity:(NSString *)string;

@end

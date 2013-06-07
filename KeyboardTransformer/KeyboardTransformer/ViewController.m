//
//  ViewController.m
//  KeyboardTransformer
//
//  Created by Administrator on 2013-01-09.
//  Copyright (c) 2013 Administrator. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

static int k_KEYBOARDWIDTH = 10;
static int k_KEYBOARDHEIGHT = 4;

@implementation ViewController
@synthesize inputTextField, keyboardLabel;
@synthesize currentKeyboard;

#pragma mark - IBActions

- (IBAction)transform:(id)sender{
    [self.inputTextField resignFirstResponder];
    NSString *inputScript = self.inputTextField.text;
    
    
    //input should be seperated by ,
    NSArray *transforms = [inputScript componentsSeparatedByString:@","];
    
    
    //solution 1 - do the transform one by one
    for (NSString *transform in transforms) {
        //check validity
        if (![self checkvalidity:transform]) {
            return;
        }
        //horizontal flip
        if ([[transform uppercaseString] isEqualToString:@"H"]) {
            NSMutableArray *newKeyboard = [[NSMutableArray alloc] initWithCapacity:k_KEYBOARDHEIGHT];
            for (NSString *eachLine in currentKeyboard) {
                int length = [eachLine length];
                NSMutableString *reverserString = [[NSMutableString alloc] initWithCapacity:length];
                for(int i = length-1; i >= 0; i--){
                    reverserString = [NSString stringWithFormat:@"%@%@",reverserString, [eachLine substringWithRange:NSMakeRange(i, 1)]];
                }
                [newKeyboard addObject:reverserString];
            }
            currentKeyboard = newKeyboard;
            [self resetKeyboard:nil];
        }
        //vertical flip
        else if ([[transform uppercaseString] isEqualToString:@"V"]) {
            NSMutableArray *newKeyboard = [[NSMutableArray alloc] initWithCapacity:k_KEYBOARDHEIGHT];
            for (int i = 0; i < k_KEYBOARDHEIGHT; i++) {
                [newKeyboard insertObject:[currentKeyboard objectAtIndex:i] atIndex:0];
            }
            currentKeyboard = newKeyboard;
            [self resetKeyboard:nil];
        }
        //shift
        else{   
            //first flatten the structure for shift;
            NSString *currentKeyboardString = @"";
            for (NSString *eachLine in currentKeyboard) {
                currentKeyboardString = [NSString stringWithFormat:@"%@%@", currentKeyboardString, eachLine];
            }
            
            int shiftIndex = [transform intValue];
            if (shiftIndex > 0) { //shift to right
                NSString *substring1 = [currentKeyboardString substringToIndex:[currentKeyboardString length] - shiftIndex];
                NSString *substring2 = [currentKeyboardString substringFromIndex:[currentKeyboardString length] - shiftIndex];
                currentKeyboardString = [NSString stringWithFormat:@"%@%@", substring2, substring1];
                [self resetKeyboard:currentKeyboardString];
            }
            else if (shiftIndex < 0){ //shift to left
                NSString *substring1 = [currentKeyboardString substringToIndex:-shiftIndex];
                NSString *substring2 = [currentKeyboardString substringFromIndex:-shiftIndex];
                currentKeyboardString = [NSString stringWithFormat:@"%@%@", substring2, substring1];
                [self resetKeyboard:currentKeyboardString];
            }
        }
    }
    
    
    //solution two - remove reverse transforms and add all the shift didn't have time to do. This solution is faster
    
}


- (BOOL)checkvalidity:(NSString *)string{
    if ([string hasPrefix:@"-"]) {
        string  = [string substringFromIndex:1];
    }
    //validate the input text
    NSPredicate *predicate = [NSPredicate predicateWithFormat:@"SELF MATCHES '[0-9]+'"];
    NSPredicate *predicateLetter = [NSPredicate predicateWithFormat:@"SELF MATCHES '[HV]'"];
    if ([predicate evaluateWithObject:[string uppercaseString]] || [predicateLetter evaluateWithObject:[string uppercaseString]]) {
        NSLog(@"passes!");
        return YES;
    } else {
        NSLog(@"fails!");
        return NO;
    }
}


- (void)resetKeyboard:(NSString *)inputString{
    NSString *outputString = @"";
    
    if ([inputString length] > 0) {
        currentKeyboard = [[NSMutableArray alloc] initWithCapacity:k_KEYBOARDHEIGHT]; //clean up
        for (int i = 1; i <= k_KEYBOARDHEIGHT; i++) {
            NSString *keyboardLine = [inputString substringToIndex:k_KEYBOARDWIDTH];
            inputString = [inputString substringFromIndex:k_KEYBOARDWIDTH];
            [currentKeyboard addObject:keyboardLine];
            outputString = [NSString stringWithFormat:@"%@\n%@", outputString, keyboardLine];
        }
    }
    else{
        for (NSString *eachLine in currentKeyboard) {
            outputString = [NSString stringWithFormat:@"%@\n%@", outputString, eachLine];
        }
    }
    
    self.keyboardLabel.text = outputString;
}

#pragma mark - view methods
- (void)viewDidLoad
{
    [super viewDidLoad];
    currentKeyboard = [[NSMutableArray alloc] initWithCapacity:k_KEYBOARDHEIGHT];
	//initial keyboard status
    [self resetKeyboard:@"1234567890qwertyuiopasdfghjkl;zxcvbnm,./"];
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end

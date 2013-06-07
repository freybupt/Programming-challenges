//
//  ViewController.m
//  googlecodeJam
//
//  Created by Liang Shi on 12-04-13.
//  Copyright (c) 2012 University of Alberta. All rights reserved.
//

#import "ViewController.h"

@implementation ViewController
@synthesize letterDictionary;


#pragma mark - View lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
    NSString *result = @"";

    NSString* path = [[NSBundle mainBundle] pathForResource:@"C-large" 
                                                     ofType:@"in"];
    NSString* content = [NSString stringWithContentsOfFile:path
                                                  encoding:NSUTF8StringEncoding
                                                     error:NULL];
    NSArray *cases = [content componentsSeparatedByString:@"\n"];
    int T = [[cases objectAtIndex:0] intValue];
    for (int caseIndex = 1; caseIndex<= T; caseIndex++) {
        NSString *thisCase = [cases objectAtIndex:caseIndex];
        NSArray *data = [thisCase componentsSeparatedByString:@" "];
        int numberofrecyles = 0;
        int lowBound = [[data objectAtIndex:0] intValue];
        int highBount = [[data objectAtIndex:1] intValue];
        //process lowbound number
        for (int lownumber = lowBound; lownumber <= highBount; lownumber++) {
            //recycle each number and see whether it's with in range
            NSString *numberstring = [NSString stringWithFormat:@"%d", lownumber];
            int lastnumber = lownumber;
            for (int i = 1; i < [numberstring length]; i++) {
                
                NSString *recycledNumberString = [NSString stringWithFormat:@"%@%@",[numberstring substringFromIndex:[numberstring length]-1], [numberstring substringToIndex:[numberstring length] -1]];
                int resycledNumber = [recycledNumberString intValue];

                if (i%2 == 0 && resycledNumber == lastnumber) {
                    break;
                }
                numberstring = recycledNumberString;
                if (resycledNumber >= lowBound && resycledNumber <= highBount && resycledNumber !=lownumber) {
                    numberofrecyles++;
                }
            }
        }
             
        numberofrecyles = numberofrecyles/2;
        
        result = [NSString stringWithFormat:@"%@Case #%d: %d\n", result, caseIndex, numberofrecyles];
    }
    
    
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDirectory = [paths objectAtIndex:0];
    NSString *filePath = [documentsDirectory stringByAppendingPathComponent:@"Question3.txt"];
    
    [result writeToFile:filePath atomically:TRUE encoding:NSUTF8StringEncoding error:NULL];
                    

}


@end

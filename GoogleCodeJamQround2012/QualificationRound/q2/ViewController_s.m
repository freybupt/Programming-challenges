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
    //question 2
    NSString* path = [[NSBundle mainBundle] pathForResource:@"A-small-attempt0" 
                                                     ofType:@"in"];
    NSString* content = [NSString stringWithContentsOfFile:path
                                                  encoding:NSUTF8StringEncoding
                                                     error:NULL];
    NSArray *cases = [content componentsSeparatedByString:@"\n"];
    NSString *result = @"";
    int T = [[cases objectAtIndex:0] intValue];
    for (int caseIndex = 1; caseIndex<= T; caseIndex++) {
        NSString *thisCase = [cases objectAtIndex:caseIndex];
        NSArray *data = [thisCase componentsSeparatedByString:@" "];
        int N = [[data objectAtIndex:0] intValue];
        int S = [[data objectAtIndex:1] intValue];
        int p = [[data objectAtIndex:2] intValue];
        int numberofgooddancer = 0;
        NSMutableArray *scores = [[NSMutableArray alloc] initWithCapacity:N];
        for (int j = 0; j < N; j++) {
            [scores addObject:[NSNumber numberWithInt:[[data objectAtIndex:3+j] intValue]]];
        }
        
        //compute the number of good dancer
        int scoreUpperBound = 3*p -2;
        int scoreLowerBound = 3*p -4;
        int numberofOkdancers = 0;
        for (int j = 0; j < [scores count]; j++) {
            int oneScore = [[scores objectAtIndex:j] intValue];
            if (oneScore >= scoreUpperBound) {
                numberofgooddancer++;
            }
            else if(oneScore >= scoreLowerBound && oneScore > 0){
                numberofOkdancers++;
            }
        }
        
        if (numberofOkdancers > S) {
            numberofgooddancer = numberofgooddancer + S;
        }
        else{
            numberofgooddancer = numberofgooddancer + numberofOkdancers;
        }
        
        result = [NSString stringWithFormat:@"%@Case #%d: %d\n", result, caseIndex, numberofgooddancer];
    }
    
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDirectory = [paths objectAtIndex:0];
    NSString *filePath = [documentsDirectory stringByAppendingPathComponent:@"Question2.txt"];
    
    [result writeToFile:filePath atomically:TRUE encoding:NSUTF8StringEncoding error:NULL];
                    

}


@end

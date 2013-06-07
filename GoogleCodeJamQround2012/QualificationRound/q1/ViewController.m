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
	// Do any additional setup after loading the view, typically from a nib.
    letterDictionary = [[NSDictionary alloc] initWithObjectsAndKeys:\
                        @"a", @"y",\
                        @"b", @"n",                                           
                        @"c", @"f",\
                        @"d", @"i",\
                        @"e", @"c",\
                        @"f", @"w",\
                        @"g", @"l",\
                        @"h", @"b",\
                        @"i", @"k",\
                        @"j", @"u",\
                        @"k", @"o",\
                        @"l", @"m",\
                        @"m", @"x",\
                        @"n", @"s",\
                        @"o", @"e",\
                        @"p", @"v",\
                        @"q", @"z",\
                        @"r", @"p",\
                        @"s", @"d",\
                        @"t", @"r",\
                        @"u", @"j",\
                        @"v", @"g",\
                        @"w", @"t",\
                        @"x", @"h",\
                        @"y", @"a",\
                        @"z", @"q",\
                        @" ", @" ",\
                        nil];
    
    //question 1
    NSString* path = [[NSBundle mainBundle] pathForResource:@"A-small-attempt1" 
                                                     ofType:@"in"];
    NSString* content = [NSString stringWithContentsOfFile:path
                                                  encoding:NSUTF8StringEncoding
                                                     error:NULL];
    NSString *result = @"";
    int lineNumber = 0;
    while([content length] > 0) {
        
        NSString *letter = [content substringToIndex:1];
        content = [content substringFromIndex:1];
        if ([letter isEqualToString:@"\n"] && [content length] > 0) {
            lineNumber++;
            if (lineNumber > 1) {
                result = [NSString stringWithFormat:@"%@%@Case #%d: ", result, letter, lineNumber];
            }
            else{
                result = [NSString stringWithFormat:@"%@Case #%d: ", result, lineNumber];
            }
            
        }
        else if ([letterDictionary objectForKey:letter]) {
            result = [NSString stringWithFormat:@"%@%@", result, [letterDictionary objectForKey:letter]];
        }
        else if(lineNumber > 0){
            result = [NSString stringWithFormat:@"%@%@", result, letter];
        }
        
        
    }
    
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDirectory = [paths objectAtIndex:0];
    NSString *filePath = [documentsDirectory stringByAppendingPathComponent:@"Question1.out"];
    
    [result writeToFile:filePath atomically:TRUE encoding:NSUTF8StringEncoding error:NULL];
    
}


@end

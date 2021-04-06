//
// Created by Florinda Cassey on 4/6/21.
//
#include "mlx.h"
#import <AppKit/NSScreen.h>

void mlx_get_screen_size(int *width, int *height)
{
	NSRect  disp = [[NSScreen mainScreen]frame];
	*height = (int)disp.size.height;
	*width = (int)disp.size.width;
}
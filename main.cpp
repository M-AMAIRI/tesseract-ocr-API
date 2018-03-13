// teserract_.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

int main()
{
	std::string outText;

	tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
	// Initialize tesseract-ocr with English, without specifying tessdata path
	if (api->Init("", "eng")) {
		fprintf(stderr, "Could not initialize tesseract.\n");
		getchar();
		exit(1);
	}
	
	// Open input image with leptonica library
	Pix *image = pixRead("image.jpg");
	api->SetImage(image);
	// Get OCR result
	outText = api->GetUTF8Text();
	printf("OCR output:\n%s", outText);

	// Destroy used object and release memory
	api->End();
	//delete outText;
	pixDestroy(&image);
	getchar();
	return 0;
}

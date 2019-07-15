# DICOM Sandbox


This project was created to explore and understand the DICOM standard--in particular, DICOM files.

The code is written to be generic and cross-platform compatible.  There are no dependencies outside of the standard C++ libraries.

The project and solution files were created with Visual Studio 2019 (version 16.1).


## Projects


### Generic Library

This is a static library that includes objects and functions that may be generally helpful across all projects.


### DICOM Library

This static library contains code that is specific to the DICOM standard, but not specific to the application usage.


### Console Reader

This is a console application that reads the DICOM data from a file, given as a command line parameter, and outputs iterpretations of all of the data elements from that file.

#### Usage

`ConsoleReader.exe <file-name>`

#### Sample Output

```
File Meta Information Group Length: 230
File Meta Information Version: (binary data, 2 bytes)
Media Storage SOP Class UID: 1.2.840.10008.5.1.4.1.1.2
Media Storage SOP Instance UID: 1.2.826.0.1.3680043.8.1055.1.20111102150758591.03296050.69180943
Transfer Syntax UID: 1.2.840.10008.1.2.4.91
Implementation Class UID: 1.2.826.0.1.3680043.8.1055.1
Implementation Version Name: dicomlibrary-100
Source Application Entity Title: DICOMLIBRARY
Specific Character Set: ISO_IR 100
Image Type: ORIGINAL\PRIMARY\AXIAL\HELIX
Instance Creation Date: 2006-10-12
Instance Creation Time: 09:16:05.000000
SOP Class UID: 1.2.840.10008.5.1.4.1.1.2
SOP Instance UID: 1.2.826.0.1.3680043.8.1055.1.20111102150758591.03296050.69180943
Study Date: 2006-10-12
Acquisition Date: 2006-10-12
Content Date: 2006-10-12
Study Time: 09:02:58.000000
Acquisition Time: 08:52:29.000000
Content Time: 08:52:29.719000
Modality: CT
Study Description: CT1 abdomen
Procedure Code Sequence
        [Item 1]
        Code Value: CTABDOM
        Coding Scheme Designator: XPLORE
        Code Meaning: CT1 abdomen
Series Description: ARTERIELLE
Referenced Performed Procedure Step Sequence
        [Item 1]
        Referenced SOP Class UID: 1.2.840.10008.3.1.2.3.3
        Referenced SOP Instance UID: 1.2.840.113704.1.111.5104.1160636572.51
Patient's Name: Anonymized
Patient ID: 0
Patient's Age: 000 years
Contrast/Bolus Agent: CONTRAST
Scan Options: HELIX
Slice Thickness: 1.0
KVP: 120
Spacing Between Slices: 0.5
Data Collection Diameter: 302
Protocol Name: ART.RENALES 12/Abdomen/Hx
(0018,1100) Decimal String: 302
(0018,1120) Decimal String: 0
(0018,1130) Decimal String: 151
(0018,1140) Code String: CW
(0018,1151) Integer String: 400
(0018,1152) Integer String: 300
(0018,1160) Short String: B
(0018,1210) Short String: B
(0018,5100) Code String: FFS
Study Instance UID: 1.2.826.0.1.3680043.8.1055.1.20111102150758591.92402465.76095170
Series Instance UID: 1.2.826.0.1.3680043.8.1055.1.20111102150758591.96842950.07877442
Series Number: 6168
Instance Number: 1
Image Position (Patient): -151.493508\-36.6564417\1295
Image Orientation (Patient): 1\0\0\0\1\0
Frame Reference UID: 1.2.840.113704.1.111.3704.1160637109.3
Slice Location: -325.00
Image Comments: JPEG 2000 lossless - Version 4.0.2 (c) Image Devices GmbH
Samples per Pixel: 1
Photometric Interpretation: MONOCHROME2
Rows: 512
Columns: 512
Pixel Spacing: 0.58984375\0.58984375
Bits Allocated: 16
Bits Stored: 12
High Bit: 11
Pixel Representation: 0
Window Center: 00050\00050
Window Width: 00350\00350
Rescale Intercept: -1000
Rescale Slope: 1
Lossy Image Compression: 01
Lossy Image Compression Ratio: 5.882680
Scheduled Procedure Step Description: CT1 abdomen
Scheduled Protocol Code Sequence
        [Item 1]
        Code Value: CTABDOM
        Coding Scheme Designator: XPLORE
        Code Meaning: CT1 abdomen
Scheduled Procedure Step ID: A10026177758
Performed Procedure Step Description: CT1 abdomen
Performed Protocol Code Sequence
        [Item 1]
        Code Value: CTABDOM
        Coding Scheme Designator: XPLORE
        Code Meaning: CT1 abdomen
Request Attributes Sequence
        [Item 1]
        Scheduled Procedure Step Description: CT1 abdomen
        Scheduled Protocol Code Sequence
                [Item 1]
                Code Value: CTABDOM
                Coding Scheme Designator: XPLORE
                Code Meaning: CT1 abdomen
        Scheduled Procedure Step ID: A10026177758
        Requested Procedure ID: A10026177757
Requested Procedure ID: A10026177757
Pixel Data
        [Basic Offset Table]
        Frame 1 offset: 0 bytes
        [Frame 1]
        89124 bytes of pixel data
```


## References


### The DICOM Standard

[Current Edition](https://www.dicomstandard.org/current/)

In particular, part 10 describes the file format, part 5 describes the encoding of different value types, and part 6 lists all of the different data elements.


### Introduction to DICOM

[Introduction to the DICOM Standard using OsiriX](https://saravanansubramanian.com/dicomintro/)

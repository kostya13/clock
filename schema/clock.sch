EESchema Schematic File Version 2
LIBS:power
LIBS:gost
LIBS:clock-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "19 mar 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L VT_NPN_BCE VT2
U 1 1 52F13E6A
P 3300 4150
F 0 "VT2" V 3500 4200 60  0000 R CNN
F 1 "КТ315" V 3100 4100 60  0000 R CNN
F 2 "" H 3300 4150 60  0001 C CNN
F 3 "" H 3300 4150 60  0001 C CNN
	1    3300 4150
	0    -1   -1   0   
$EndComp
$Comp
L POWER_GND #?
U 1 1 52F13E15
P 7800 2000
F 0 "#?" V 7750 1950 60  0001 C CNN
F 1 "POWER_GND" V 7850 1950 60  0001 C CNN
F 2 "" H 7800 2000 60  0001 C CNN
F 3 "" H 7800 2000 60  0001 C CNN
	1    7800 2000
	1    0    0    -1  
$EndComp
$Comp
L BAT GB1
U 1 1 52F13DFB
P 7700 5050
F 0 "GB1" H 7725 4925 60  0000 L CNN
F 1 "3V" H 7725 4725 60  0000 L CNN
F 2 "" H 7700 5050 60  0001 C CNN
F 3 "" H 7700 5050 60  0001 C CNN
	1    7700 5050
	0    -1   -1   0   
$EndComp
$Comp
L SA_1-2_CL SA1
U 1 1 52F13A0C
P 7000 2000
F 0 "SA1" H 7200 2050 50  0000 C CNN
F 1 "SA_1-2_CL" H 7000 1900 60  0001 C CNN
F 2 "" H 7000 2000 60  0001 C CNN
F 3 "" H 7000 2000 60  0001 C CNN
	1    7000 2000
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 52F1EB00
P 7050 2600
F 0 "R2" V 7130 2600 50  0000 C CNN
F 1 "1к" V 7050 2600 50  0000 C CNN
F 2 "" H 7050 2600 60  0000 C CNN
F 3 "" H 7050 2600 60  0000 C CNN
	1    7050 2600
	0    -1   -1   0   
$EndComp
$Comp
L R R1
U 1 1 52F4BCDC
P 7050 2400
F 0 "R1" V 6950 2400 50  0000 C CNN
F 1 "1к" V 7050 2400 50  0000 C CNN
F 2 "" H 7050 2400 60  0000 C CNN
F 3 "" H 7050 2400 60  0000 C CNN
	1    7050 2400
	0    1    1    0   
$EndComp
$Comp
L VT_NPN_BCE VT1
U 1 1 52F4C8E0
P 3300 3450
F 0 "VT1" V 3500 3500 60  0000 R CNN
F 1 "КТ315" V 3100 3400 60  0000 R CNN
F 2 "" H 3300 3450 60  0001 C CNN
F 3 "" H 3300 3450 60  0001 C CNN
	1    3300 3450
	0    -1   -1   0   
$EndComp
$Comp
L ATTINY2313 DD1
U 1 1 52F138FE
P 5800 2000
F 0 "DD1" H 6300 2150 60  0000 C CNN
F 1 "ATTINY2313" H 6300 0   60  0000 C CNN
F 2 "" H 5800 2000 60  0001 C CNN
F 3 "" H 5800 2000 60  0001 C CNN
	1    5800 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 3600 6800 3400
$Comp
L POWER_VCC #?
U 1 1 52F4D84D
P 6900 3600
F 0 "#?" V 6700 3350 60  0001 C CNN
F 1 "POWER_VCC" H 7050 3500 60  0001 C CNN
F 2 "" H 6900 3600 60  0000 C CNN
F 3 "" H 6900 3600 60  0000 C CNN
	1    6900 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6900 3600 6800 3600
$Comp
L POWER_GND #?
U 1 1 52F4D89D
P 9150 2450
F 0 "#?" V 9100 2400 60  0001 C CNN
F 1 "POWER_GND" V 9200 2400 60  0001 C CNN
F 2 "" H 9150 2450 60  0001 C CNN
F 3 "" H 9150 2450 60  0001 C CNN
	1    9150 2450
	1    0    0    -1  
$EndComp
$Comp
L POWER_VCC #?
U 1 1 52F4D8A9
P 9150 2100
F 0 "#?" V 8950 1850 60  0001 C CNN
F 1 "POWER_VCC" H 9300 2000 60  0001 C CNN
F 2 "" H 9150 2100 60  0000 C CNN
F 3 "" H 9150 2100 60  0000 C CNN
	1    9150 2100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5800 3600 5650 3600
$Comp
L POWER_GND #?
U 1 1 52FDA0A6
P 6950 3800
F 0 "#?" V 6900 3750 60  0001 C CNN
F 1 "POWER_GND" V 7000 3750 60  0001 C CNN
F 2 "" H 6950 3800 60  0001 C CNN
F 3 "" H 6950 3800 60  0001 C CNN
	1    6950 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 3800 7400 3800
$Comp
L GIC_DS1307 DD2
U 1 1 5327F909
P 7450 4650
F 0 "DD2" H 7950 4800 60  0000 C CNN
F 1 "DS1307" H 7950 3850 60  0000 C CNN
F 2 "~" H 7450 4650 60  0000 C CNN
F 3 "~" H 7450 4650 60  0000 C CNN
	1    7450 4650
	-1   0    0    -1  
$EndComp
$Comp
L SA_1-2_CL SA2
U 1 1 5327F9B0
P 7000 2200
F 0 "SA2" H 7200 2250 50  0000 C CNN
F 1 "SA_1-2_CL" H 7000 2100 60  0001 C CNN
F 2 "" H 7000 2200 60  0001 C CNN
F 3 "" H 7000 2200 60  0001 C CNN
	1    7000 2200
	1    0    0    -1  
$EndComp
$Comp
L VT_NPN_BCE VT4
U 1 1 5327FA48
P 3300 6500
F 0 "VT4" V 3500 6550 60  0000 R CNN
F 1 "КТ315" V 3100 6450 60  0000 R CNN
F 2 "" H 3300 6500 60  0001 C CNN
F 3 "" H 3300 6500 60  0001 C CNN
	1    3300 6500
	0    -1   -1   0   
$EndComp
$Comp
L VT_NPN_BCE VT3
U 1 1 5327FA4E
P 3300 5850
F 0 "VT3" V 3500 5900 60  0000 R CNN
F 1 "КТ315" V 3100 5800 60  0000 R CNN
F 2 "" H 3300 5850 60  0001 C CNN
F 3 "" H 3300 5850 60  0001 C CNN
	1    3300 5850
	0    -1   -1   0   
$EndComp
$Comp
L CONN_02_F XS1
U 1 1 5327FAC2
P 9150 2200
F 0 "XS1" H 9400 2300 60  0000 C CNN
F 1 "CONN_02_F" H 9500 2000 60  0000 C CNN
F 2 "~" H 9150 2200 60  0000 C CNN
F 3 "~" H 9150 2200 60  0000 C CNN
	1    9150 2200
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 5327FACF
P 5550 2000
F 0 "R5" V 5475 2000 50  0000 C CNN
F 1 "68" V 5550 2000 50  0000 C CNN
F 2 "" H 5550 2000 60  0000 C CNN
F 3 "" H 5550 2000 60  0000 C CNN
	1    5550 2000
	0    1    1    0   
$EndComp
$Comp
L R R6
U 1 1 5327FAF3
P 5550 2200
F 0 "R6" V 5475 2200 50  0000 C CNN
F 1 "68" V 5550 2200 50  0000 C CNN
F 2 "" H 5550 2200 60  0000 C CNN
F 3 "" H 5550 2200 60  0000 C CNN
	1    5550 2200
	0    1    1    0   
$EndComp
$Comp
L R R7
U 1 1 5327FB2C
P 5550 2400
F 0 "R7" V 5475 2400 50  0000 C CNN
F 1 "68" V 5550 2400 50  0000 C CNN
F 2 "" H 5550 2400 60  0000 C CNN
F 3 "" H 5550 2400 60  0000 C CNN
	1    5550 2400
	0    1    1    0   
$EndComp
$Comp
L R R8
U 1 1 5327FB32
P 5550 2600
F 0 "R8" V 5475 2600 50  0000 C CNN
F 1 "68" V 5550 2600 50  0000 C CNN
F 2 "" H 5550 2600 60  0000 C CNN
F 3 "" H 5550 2600 60  0000 C CNN
	1    5550 2600
	0    1    1    0   
$EndComp
$Comp
L R R9
U 1 1 5327FB38
P 5550 2800
F 0 "R9" V 5475 2800 50  0000 C CNN
F 1 "68" V 5550 2800 50  0000 C CNN
F 2 "" H 5550 2800 60  0000 C CNN
F 3 "" H 5550 2800 60  0000 C CNN
	1    5550 2800
	0    1    1    0   
$EndComp
$Comp
L R R10
U 1 1 5327FB3E
P 5550 3000
F 0 "R10" V 5475 3000 50  0000 C CNN
F 1 "68" V 5550 3000 50  0000 C CNN
F 2 "" H 5550 3000 60  0000 C CNN
F 3 "" H 5550 3000 60  0000 C CNN
	1    5550 3000
	0    1    1    0   
$EndComp
$Comp
L R R11
U 1 1 5327FB44
P 5550 3200
F 0 "R11" V 5475 3200 50  0000 C CNN
F 1 "68" V 5550 3200 50  0000 C CNN
F 2 "" H 5550 3200 60  0000 C CNN
F 3 "" H 5550 3200 60  0000 C CNN
	1    5550 3200
	0    1    1    0   
$EndComp
NoConn ~ 5800 3400
NoConn ~ 6800 3200
$Comp
L R R3
U 1 1 5327FDFB
P 7050 2800
F 0 "R3" V 6950 2800 50  0000 C CNN
F 1 "1к" V 7050 2800 50  0000 C CNN
F 2 "" H 7050 2800 60  0000 C CNN
F 3 "" H 7050 2800 60  0000 C CNN
	1    7050 2800
	0    1    1    0   
$EndComp
$Comp
L R R4
U 1 1 5327FE01
P 7050 3000
F 0 "R4" V 6950 3000 50  0000 C CNN
F 1 "1к" V 7050 3000 50  0000 C CNN
F 2 "" H 7050 3000 60  0000 C CNN
F 3 "" H 7050 3000 60  0000 C CNN
	1    7050 3000
	0    1    1    0   
$EndComp
Wire Wire Line
	9150 2200 9150 2100
Wire Wire Line
	9150 2300 9150 2450
Wire Wire Line
	7200 2000 7800 2000
Wire Wire Line
	7200 2200 7550 2200
Wire Wire Line
	7550 2200 7550 2000
Connection ~ 7550 2000
$Comp
L POWER_VCC #?
U 1 1 5327FFC0
P 6450 4450
F 0 "#?" V 6250 4200 60  0001 C CNN
F 1 "POWER_VCC" H 6600 4350 60  0001 C CNN
F 2 "" H 6450 4450 60  0000 C CNN
F 3 "" H 6450 4450 60  0000 C CNN
	1    6450 4450
	0    1    -1   0   
$EndComp
$Comp
L POWER_GND #?
U 1 1 5327FFB1
P 7450 5250
F 0 "#?" V 7400 5200 60  0001 C CNN
F 1 "POWER_GND" V 7500 5200 60  0001 C CNN
F 2 "" H 7450 5250 60  0001 C CNN
F 3 "" H 7450 5250 60  0001 C CNN
	1    7450 5250
	1    0    0    -1  
$EndComp
$Comp
L LED_7SEG_2_2 HG1
U 1 1 53280055
P 3950 2000
F 0 "HG1" H 4450 2150 60  0000 C CNN
F 1 "DA08-11EWA" H 4450 250 60  0000 C CNN
F 2 "~" H 3950 2000 60  0000 C CNN
F 3 "~" H 3950 2000 60  0000 C CNN
	1    3950 2000
	1    0    0    -1  
$EndComp
$Comp
L LED_7SEG_2_2 HG2
U 1 1 53280062
P 3950 4350
F 0 "HG2" H 4450 4500 60  0000 C CNN
F 1 "DA08-11EWA" H 4450 2600 60  0000 C CNN
F 2 "~" H 3950 4350 60  0000 C CNN
F 3 "~" H 3950 4350 60  0000 C CNN
	1    3950 4350
	1    0    0    -1  
$EndComp
Entry Wire Line
	4950 2000 5050 2100
Entry Wire Line
	4950 2200 5050 2300
Entry Wire Line
	4950 2400 5050 2500
Entry Wire Line
	4950 2600 5050 2700
Entry Wire Line
	4950 3000 5050 3100
Entry Wire Line
	4950 2800 5050 2900
Entry Wire Line
	4950 3200 5050 3300
Entry Wire Line
	4950 4350 5050 4450
Entry Wire Line
	4950 4550 5050 4650
Entry Wire Line
	4950 4750 5050 4850
Entry Wire Line
	4950 4950 5050 5050
Entry Wire Line
	4950 5150 5050 5250
Entry Wire Line
	4950 5350 5050 5450
Entry Wire Line
	4950 5550 5050 5650
Entry Wire Line
	3850 4250 3950 4350
Entry Wire Line
	3850 4450 3950 4550
Entry Wire Line
	3850 4650 3950 4750
Entry Wire Line
	3850 4850 3950 4950
Entry Wire Line
	3850 5050 3950 5150
Entry Wire Line
	3850 5250 3950 5350
Entry Wire Line
	3850 5450 3950 5550
Entry Wire Line
	3850 3100 3950 3200
Entry Wire Line
	3850 2900 3950 3000
Entry Wire Line
	3850 2700 3950 2800
Entry Wire Line
	3850 2500 3950 2600
Entry Wire Line
	3850 2300 3950 2400
Entry Wire Line
	3850 2100 3950 2200
Entry Wire Line
	3850 1900 3950 2000
Wire Bus Line
	3850 1700 5050 1700
Wire Wire Line
	4950 3600 4950 4050
Wire Wire Line
	4950 4050 3450 4050
Wire Wire Line
	3950 3600 3650 3600
Wire Wire Line
	3650 3600 3650 3350
Wire Wire Line
	3650 3350 3450 3350
Wire Wire Line
	4950 5950 4950 6400
Wire Wire Line
	4950 6400 3450 6400
Wire Wire Line
	3950 5950 3600 5950
Wire Wire Line
	3600 5950 3600 5750
Wire Wire Line
	3600 5750 3450 5750
Wire Wire Line
	3050 6400 3150 6400
Wire Wire Line
	3050 3250 3050 6400
$Comp
L POWER_VCC #?
U 1 1 53280317
P 3050 3250
F 0 "#?" V 2850 3000 60  0001 C CNN
F 1 "POWER_VCC" H 3200 3150 60  0001 C CNN
F 2 "" H 3050 3250 60  0000 C CNN
F 3 "" H 3050 3250 60  0000 C CNN
	1    3050 3250
	0    1    -1   0   
$EndComp
Wire Wire Line
	3150 3350 3050 3350
Connection ~ 3050 3350
Wire Wire Line
	3150 4050 3050 4050
Connection ~ 3050 4050
Wire Wire Line
	3150 5750 3050 5750
Connection ~ 3050 5750
Entry Wire Line
	2850 6600 2950 6700
Wire Wire Line
	3300 6700 2950 6700
Entry Wire Line
	2850 5950 2950 6050
Entry Wire Line
	2850 4250 2950 4350
Entry Wire Line
	2850 3550 2950 3650
Wire Wire Line
	3300 3650 2950 3650
Wire Wire Line
	3300 4350 2950 4350
Wire Wire Line
	3300 6050 2950 6050
Wire Bus Line
	2850 1500 2850 6600
Text Label 3950 2000 0    60   ~ 0
A
Text Label 4950 2000 0    60   ~ 0
A
Text Label 4950 4350 0    60   ~ 0
A
Text Label 3950 4350 2    60   ~ 0
A
Entry Wire Line
	7300 2400 7400 2500
Entry Wire Line
	7300 2600 7400 2700
Entry Wire Line
	7300 2800 7400 2900
Entry Wire Line
	7300 3000 7400 3100
Wire Bus Line
	7400 1500 7400 3100
Wire Bus Line
	7400 1500 2850 1500
Text Label 7300 2400 0    60   ~ 0
VT1
Text Label 7300 2600 0    60   ~ 0
VT2
Text Label 7300 2800 0    60   ~ 0
VT3
Text Label 7300 3000 0    60   ~ 0
VT4
Text Label 2950 6700 0    60   ~ 0
VT4
Text Label 2950 6050 0    60   ~ 0
VT3
Text Label 2950 4350 0    60   ~ 0
VT2
Text Label 2950 3650 0    60   ~ 0
VT1
Wire Wire Line
	6450 5250 5650 5250
Wire Wire Line
	5650 5250 5650 3600
Wire Wire Line
	5800 3800 5800 5050
Wire Wire Line
	5800 5050 6450 5050
Wire Wire Line
	7450 4850 8300 4850
Wire Wire Line
	8300 4850 8300 4500
Wire Wire Line
	7450 4650 7950 4650
Wire Wire Line
	7950 4650 7950 4500
Entry Wire Line
	5050 1900 5150 2000
Entry Wire Line
	5050 2100 5150 2200
Entry Wire Line
	5050 2300 5150 2400
Entry Wire Line
	5050 2500 5150 2600
Entry Wire Line
	5050 2700 5150 2800
Entry Wire Line
	5050 2900 5150 3000
Entry Wire Line
	5050 3100 5150 3200
Wire Wire Line
	5300 2000 5150 2000
Wire Wire Line
	5300 2200 5150 2200
Wire Wire Line
	5300 2400 5150 2400
Wire Wire Line
	5300 2600 5150 2600
Wire Wire Line
	5300 2800 5150 2800
Wire Wire Line
	5300 3000 5150 3000
Wire Wire Line
	5300 3200 5150 3200
Text Label 5150 2000 0    60   ~ 0
A
NoConn ~ 6450 4850
Text Label 5150 2200 0    60   ~ 0
B
Text Label 5150 2400 0    60   ~ 0
C
Text Label 5150 2600 0    60   ~ 0
D
Text Label 5150 2800 0    60   ~ 0
E
Text Label 5150 3000 0    60   ~ 0
F
Text Label 5150 3200 0    60   ~ 0
G
Text Label 4950 2200 0    60   ~ 0
B
Text Label 3950 2200 0    60   ~ 0
B
Text Label 4950 4550 0    60   ~ 0
B
Text Label 3950 4550 0    60   ~ 0
B
Text Label 4950 2400 0    60   ~ 0
C
Text Label 3950 2400 0    60   ~ 0
C
Text Label 4950 2600 0    60   ~ 0
D
Text Label 3950 2600 0    60   ~ 0
D
Text Label 3950 2800 0    60   ~ 0
E
Text Label 4950 2800 0    60   ~ 0
E
Text Label 4950 3000 0    60   ~ 0
F
Text Label 3950 3000 0    60   ~ 0
F
Text Label 3950 3200 0    60   ~ 0
G
Text Label 4950 3200 0    60   ~ 0
G
Text Label 3950 4750 0    60   ~ 0
C
Text Label 4950 4750 0    60   ~ 0
C
Text Label 4950 4950 0    60   ~ 0
D
Text Label 3950 4950 0    60   ~ 0
D
Text Label 3950 5150 0    60   ~ 0
E
Text Label 4950 5150 0    60   ~ 0
E
Text Label 3950 5350 0    60   ~ 0
F
Text Label 4950 5350 0    60   ~ 0
F
Text Label 3950 5550 0    60   ~ 0
G
Text Label 4950 5550 0    60   ~ 0
G
NoConn ~ 4950 3400
NoConn ~ 3950 3400
NoConn ~ 3950 5750
NoConn ~ 4950 5750
Wire Bus Line
	5050 1700 5050 5650
Wire Bus Line
	3850 1700 3850 5450
$Comp
L PWR_FLAG #FLG?
U 1 1 53280E20
P 8950 2150
F 0 "#FLG?" H 8950 2245 30  0001 C CNN
F 1 "PWR_FLAG" H 8950 2330 30  0000 C CNN
F 2 "" H 8950 2150 60  0000 C CNN
F 3 "" H 8950 2150 60  0000 C CNN
	1    8950 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	9150 2200 8950 2200
Wire Wire Line
	8950 2200 8950 2150
$Comp
L PWR_FLAG #FLG?
U 1 1 53280E6B
P 8150 5500
F 0 "#FLG?" H 8150 5595 30  0001 C CNN
F 1 "PWR_FLAG" H 8150 5680 30  0000 C CNN
F 2 "" H 8150 5500 60  0000 C CNN
F 3 "" H 8150 5500 60  0000 C CNN
	1    8150 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 5050 7700 5050
Wire Wire Line
	7450 5250 8150 5250
Wire Wire Line
	8150 5250 8150 5050
Wire Wire Line
	8150 5500 7700 5500
Wire Wire Line
	7700 5500 7700 5050
Connection ~ 6950 3800
$Comp
L PWR_FLAG #FLG?
U 1 1 532818D0
P 7400 3800
F 0 "#FLG?" H 7400 3895 30  0001 C CNN
F 1 "PWR_FLAG" H 7400 3980 30  0000 C CNN
F 2 "" H 7400 3800 60  0000 C CNN
F 3 "" H 7400 3800 60  0000 C CNN
	1    7400 3800
	1    0    0    -1  
$EndComp
$Comp
L CRYSTAL BQ1
U 1 1 53281BA9
P 7950 4500
F 0 "BQ1" H 8150 4700 60  0000 C CNN
F 1 "CRYSTAL" H 8250 4300 60  0001 C CNN
F 2 "~" H 7950 4500 60  0000 C CNN
F 3 "~" H 7950 4500 60  0000 C CNN
	1    7950 4500
	1    0    0    -1  
$EndComp
$Comp
L LED VD1
U 1 1 53282BF6
P 9150 4200
F 0 "VD1" H 9150 4400 60  0000 C CNN
F 1 "LED" H 9200 4000 60  0000 C CNN
F 2 "~" H 9150 4200 60  0000 C CNN
F 3 "~" H 9150 4200 60  0000 C CNN
	1    9150 4200
	0    1    1    0   
$EndComp
$Comp
L LED VD2
U 1 1 53282C12
P 9150 4700
F 0 "VD2" H 9150 4900 60  0000 C CNN
F 1 "LED" H 9200 4500 60  0000 C CNN
F 2 "~" H 9150 4700 60  0000 C CNN
F 3 "~" H 9150 4700 60  0000 C CNN
	1    9150 4700
	0    1    1    0   
$EndComp
$Comp
L R R12
U 1 1 53282C1A
P 9150 5200
F 0 "R12" V 9230 5200 50  0000 C CNN
F 1 "R" V 9150 5200 50  0000 C CNN
F 2 "~" H 9150 5200 60  0000 C CNN
F 3 "~" H 9150 5200 60  0000 C CNN
	1    9150 5200
	1    0    0    -1  
$EndComp
$Comp
L POWER_GND #?
U 1 1 53282C27
P 9150 5450
F 0 "#?" V 9100 5400 60  0001 C CNN
F 1 "POWER_GND" V 9200 5400 60  0001 C CNN
F 2 "" H 9150 5450 60  0001 C CNN
F 3 "" H 9150 5450 60  0001 C CNN
	1    9150 5450
	1    0    0    -1  
$EndComp
$Comp
L POWER_VCC #?
U 1 1 53282C2D
P 9150 3950
F 0 "#?" V 8950 3700 60  0001 C CNN
F 1 "POWER_VCC" H 9300 3850 60  0001 C CNN
F 2 "" H 9150 3950 60  0000 C CNN
F 3 "" H 9150 3950 60  0000 C CNN
	1    9150 3950
	0    1    -1   0   
$EndComp
$Comp
L R R14
U 1 1 53296CF2
P 6250 4700
F 0 "R14" H 6350 4700 50  0000 C CNN
F 1 "R" V 6250 4700 50  0000 C CNN
F 2 "~" H 6250 4700 60  0000 C CNN
F 3 "~" H 6250 4700 60  0000 C CNN
	1    6250 4700
	1    0    0    -1  
$EndComp
$Comp
L R R13
U 1 1 53296CF8
P 6050 4700
F 0 "R13" H 5950 4750 50  0000 C CNN
F 1 "R" V 6050 4700 50  0000 C CNN
F 2 "~" H 6050 4700 60  0000 C CNN
F 3 "~" H 6050 4700 60  0000 C CNN
	1    6050 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 4450 6050 4450
Wire Wire Line
	6450 4650 6450 4450
Wire Wire Line
	6250 4950 6250 5050
Connection ~ 6250 5050
Wire Wire Line
	6050 4950 6050 5250
Connection ~ 6050 5250
$EndSCHEMATC

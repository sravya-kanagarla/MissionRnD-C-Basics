/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int validate(int date, int mon, int year) {
	int i;
	for (i = 0; year > 0; i++)
		year /= 10;
	if (i != 4)
		return 1;
	if (mon < 1 || mon > 12) {
		return 1;
	}
	else {
		if (mon == 2) {
			if (!(((year % 4) && !(year % 100)) || (year % 400)))  {
				if (date < 1 || date > 29) {
					return 1;
				}
				else if (date < 1 || date > 28) {
					return 1;
				}
			}
		}
		else if (mon == 4 || mon == 6 || mon == 9 || mon == 11) {
			if (date < 1 || date > 30) {
				return 1;
			}
		}
		else {
			if (date < 1 || date > 31) {
				return 1;
			}
		}
	}
	return 0;
}

int divide(char *dob, int s, int e) {
	int num = 0;
	while (s < e) {
		num = num * 10 + dob[s] - '0';
		s++;
	}
	return num;
}

int isOlder(char *dob1, char *dob2) {
	int date1 = divide(dob1, 0, 2);
	int date2 = divide(dob2, 0, 2);
	int mon1 = divide(dob1, 3, 5);
	int mon2 = divide(dob2, 3, 5);
	int year1 = divide(dob1, 6, 10);
	int year2 = divide(dob2, 6, 10);
	if (validate(date1, mon1, year1))
		return -1;
	if (validate(date2, mon2, year2))
		return -1;
	if (year1 < year2) {
		return 1;
	}
	else if (year1 > year2) {
		return 2;
	}
	else {
		if (mon1 < mon2) {
			return 1;
		}
		else if (mon1 > mon2) {
			return 2;
		}
		else {
			if (date1 < date2) {
				return 1;
			}
			else if (date1 > date2) {
				return 2;
			}
			else {
				return 0;
			}
		}
	}
}

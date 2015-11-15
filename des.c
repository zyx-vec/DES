#include <stdio.h>
#include <string.h>
#include <time.h>

int initial_msg_permutatoin[] = {

	58, 50, 42, 34, 26, 18, 10, 2,
	60, 52, 44, 36, 28, 20, 12, 4,
	62, 54, 46, 38, 30, 22, 14, 6,
	64, 56, 48, 40, 32, 24, 16, 8,
	57, 49, 41, 33, 25, 17,  9, 1,
	59, 51, 43, 35, 27, 19, 11, 3,
	61, 53, 45, 37, 29, 21, 13, 5,
	63, 55, 47, 39, 31, 23, 15, 7

};

int reverse_msg_permutation[] = {

	40, 8, 48, 16, 56, 24, 64, 32,
	39, 7, 47, 15, 55, 23, 63, 31,
	38, 6, 46, 14, 54, 22, 62, 30,
	37, 5, 45, 13, 53, 21, 61, 29,
	36, 4, 44, 12, 52, 20, 60, 28,
	35, 3, 43, 11, 51, 19, 59, 27,
	34, 2, 42, 10, 50, 18, 58, 26,
	33, 1, 41,  9, 49, 17, 57, 25

};

int msg_expansion[] = {

	32,  1,  2,  3,  4,  5,
	 4,  5,  6,  7,  8,  9,
	 8,  9, 10, 11, 12, 13,
	12, 13, 14, 15, 16, 17,
	16, 17, 18, 19, 20, 21,
	20, 21, 22, 23, 24, 25,
	24, 25, 26, 27, 28, 29,
	28, 29, 30, 31, 32,  1

};

int S1[] = {
	14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7,
	 0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8,
	 4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0,
	15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13
};

int S2[] = {
	15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10,
	 3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5,
	 0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15,
	13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9
};

int S3[] = {
	10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8,
	13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1,
	13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7,
	 1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12
};

int S4[] = {
	 7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15,
	13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9,
	10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4,
	 3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14
};

int S5[] = {
	 2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9,
	14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6,
	 4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14,
	11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3
};

int S6[] = {
	12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11,
	10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8,
	 9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6,
	 4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13
};

int S7[] = {
	 4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1,
	13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6,
	 1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2,
	 6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12
};

int S8[] = {
	13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7,
	 1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2,
	 7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8,
	 2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11
};

int permutation_in_fun[] = {
	16,  7, 20, 21, 29, 12, 28, 17,
	 1, 15, 23, 26,  5, 18, 31, 10,
	 2,  8, 24, 14, 32, 27,  3,  9,
	19, 13, 30,  6, 22, 11,  4, 25
};

// key's operation table
int initial_key_permutatoin[] = {

	57, 49,  41, 33,  25,  17,  9,
	 1, 58,  50, 42,  34,  26, 18,
	10,  2,  59, 51,  43,  35, 27,
	19, 11,   3, 60,  52,  44, 36,
	63, 55,  47, 39,  31,  23, 15,
	 7, 62,  54, 46,  38,  30, 22,
	14,  6,  61, 53,  45,  37, 29,
	21, 13,   5, 28,  20,  12,  4

};

int round_key_substitution[] = {

	14, 17, 11, 24,  1,  5,  3, 28,
	15,  6, 21, 10, 23, 19, 12,  4,
	26,  8, 16,  7, 27, 20, 13,  2,
	41, 52, 31, 37, 47, 55, 30, 40,
	51, 45, 33, 48, 44, 49, 39, 56,
	34, 53, 46, 42, 50, 36, 29, 32

};

int key_round_shift_e[] = {
	-1, 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1
};
int key_round_shift_d[] = {
	-1, 0, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1
};


//unsigned char round_d[16][6];
typedef unsigned long long BIT_64;
typedef unsigned int BIT_32;

BIT_64 round_sub_key[16];
BIT_64 main_key;

FILE* in;
FILE* out;
#define MAX_SIZE 8192
unsigned char buf[MAX_SIZE+5];
unsigned char cipher[MAX_SIZE+5];


void generate_round_key_e(BIT_64 main_key) {
	BIT_64 key_56 = 0;
	int i, shift_size;
	for (i = 0; i < 56; i++) {
		shift_size = initial_key_permutatoin[i]-1;
		BIT_64 bit;
		bit = 0x01 & (main_key >> shift_size);
		key_56 |= (bit << (55-i));
	}

	BIT_32 left, right, all_1 = (1<<28)-1;
	left = (key_56 >> 28) & all_1;
	right = key_56 & all_1;
	i = 0;
	for (i = 0; i < 16; i++) {
		int shift_e = key_round_shift_e[i+1];
		BIT_32 upper_l = ((1<<shift_e )-1) & (left >> (28-shift_e));
		BIT_32 upper_r = ((1<<shift_e )-1) & (right >> (28-shift_e));
		left = ((left << shift_e) | upper_l) & all_1;
		right = ((right << shift_e) | upper_r) & all_1;

		key_56 = 0;
		key_56 = ((key_56 | left) << 28) | right;
		BIT_64 round_key = 0;
		int j;
		for (j = 0; j < 48; j++) {
			int pc_2 = round_key_substitution[j]-1;
			round_key |= ((key_56>>pc_2) & 0x01) << (47-j);
		}
		round_sub_key[i] = round_key;
	}
}

void generate_round_key_d(BIT_64 main_key) {
	BIT_64 key_56 = 0;
	int i, shift_size;
	for (i = 0; i < 56; i++) {
		shift_size = initial_key_permutatoin[i]-1;
		BIT_64 bit;
		bit = 0x01 & (main_key >> shift_size);
		key_56 |= (bit << (55-i));
	}

	BIT_32 left, right, all_1 = (1<<28)-1;
	left = (key_56 >> 28) & all_1;
	right = key_56 & all_1;
	i = 0;
	for (i = 0; i < 16; i++) {
		int shift_d = key_round_shift_d[i+1];
		BIT_32 lower_l = ((1<<shift_d)-1) & left;
		BIT_32 lower_r = ((1<<shift_d)-1) & right;

		left = (left >> shift_d) | (lower_l << (28-shift_d));
		right = (right >> shift_d) | (lower_r << (28-shift_d));

		key_56 = 0;
		key_56 = ((key_56 | left) << 28) | right;

		BIT_64 round_key = 0;
		int j;
		for (j = 0; j < 48; j++) {
			int pc_2 = round_key_substitution[j]-1;
			round_key |= ((key_56>>pc_2) & 0x01) << (47-j);
		}
		round_sub_key[i] = round_key;
	}
}


void process_msg(char* msg) {
	int len = strlen(msg);
	int i, ii;
	for (ii = 0; ii < MAX_SIZE; ii+=8) {

		BIT_64 msg_block = 0;
		BIT_64 msg_mask = 0xFF;
		BIT_64 ch[8];

		for (; ;) {
			ch[0] = msg[ii] & msg_mask;
			ch[1] = msg[ii+1] & msg_mask;
			ch[2] = msg[ii+2] & msg_mask;
			ch[3] = msg[ii+3] & msg_mask;
			ch[4] = msg[ii+4] & msg_mask;
			ch[5] = msg[ii+5] & msg_mask;
			ch[6] = msg[ii+6] & msg_mask;
			ch[7] = msg[ii+7] & msg_mask;
			msg_block += ch[0] << 56;
			msg_block += ch[1] << 48;
			msg_block += ch[2] << 40;
			msg_block += ch[3] << 32;
			msg_block += ch[4] << 24;
			msg_block += ch[5] << 16;
			msg_block += ch[6] << 8;
			msg_block += ch[7];
			//printf("msg_block = 0x%llX\n", msg_block);
			break;
		}
		//printf("%llX\n", msg_block);

		//msg_block = 0x8DD15039618E534F;

		BIT_64 tmp = msg_block;
		msg_block = 0;
		
		for (i = 0; i < 64; i++) {
			int index = initial_msg_permutatoin[i]-1;
			BIT_64 one = 1;
			BIT_64 t = one << (63-index);
			msg_block |= ((t & tmp) >> (63-index)) << (63-i);
		}

		BIT_32 left, right, all_1 = 0xFFFFFFFF;
		left = msg_block >> 32;
		right = msg_block & all_1;

		// 16 rounds encryption
		for (i = 0; i < 16; i++) {
			BIT_32 tmp = left;
			left = right;

			// f-function
			int j;
			BIT_64 er = 0;
			for (j = 0; j < 48; j++) {
				BIT_64 one = 1;
				int index = msg_expansion[j]-1;
				BIT_64 bit = (right >> (31-index)) & one;
				er |= bit << (47-j);
			}

			er = er ^ round_sub_key[i];	// last 48 bits

			BIT_32 s_box_o = 0;			// ouput of s-box 32 bits
			unsigned int row, col;
			BIT_32 data;
			BIT_32 col_mask = 0x0F;


			row = (((er >> 47)&0x01)<<1) + ((er >> 42)&0x01);	//6*7	s1
			col = (er >> 43) & col_mask;
			data = S1[row*16+col];
			s_box_o |= data << 28;

			row = (((er >> 41)&0x01)<<1) + ((er >> 36)&0x01);	//6*6 	s2
			col = (er >> 37) & col_mask;
			data = S2[row*16+col];
			s_box_o |= data << 24;

			row = (((er >> 35)&0x01)<<1) + ((er >> 30)&0x01);	//6*5 	s3
			col = (er >> 31) & col_mask;
			data = S3[row*16+col];
			s_box_o |= data << 20;

			row = (((er >> 29)&0x01)<<1) + ((er >> 24)&0x01);	//6*4 	s4
			col = (er >> 25) & col_mask;
			data = S4[row*16+col];
			s_box_o |= data << 16;

			row = (((er >> 23)&0x01)<<1) + ((er >> 18)&0x01);	//6*3 	s5
			col = (er >> 19) & col_mask;
			data = S5[row*16+col];
			s_box_o |= data << 12;

			row = (((er >> 17)&0x01)<<1) + ((er >> 12)&0x01);	//6*2 	s6
			col = (er >> 13) & col_mask;
			data = S6[row*16+col];
			s_box_o |= data << 8;

			row = (((er >> 11)&0x01)<<1) + ((er >> 6)&0x01);	//6*1 	s7
			col = (er >> 7) & col_mask;
			data = S7[row*16+col];
			s_box_o |= data << 4;

			row = (((er >> 5)&0x01)<<1) + ((er >> 0)&0x01);		//6*0 	s8
			col = (er >> 1) & col_mask;
			data = S8[row*16+col];
			s_box_o |= data << 0;

			// permutation in fun
			BIT_32 fo = 0;
			for (j = 0; j < 32; j++) {
				int index = permutation_in_fun[j]-1;
				BIT_32 one = 1;
				fo |= ((s_box_o >> (31-index)) & one) << (31-j);
			}

			right = fo ^ tmp;	// trick corner.
		}

		tmp = left;
		left = right;
		right = tmp;

		msg_block = 0;
		msg_block |= (left | msg_block) << 32;
		msg_block |= right;

		// reverse initial permutation
		BIT_64 cipher_block = 0;
		for (i = 0; i < 64; i++) {
			int index = reverse_msg_permutation[i]-1;
			BIT_64 one = 1;
			cipher_block |= ((msg_block >> (63-index)) & one) << (63-i);
		}
		//printf("cipher_block = 0x%llX\n", cipher_block);

		unsigned char mask = 0xFF;
		cipher[ii] = (cipher_block >> 56) & mask;
		cipher[ii+1] = (cipher_block >> 48) & mask;
		cipher[ii+2] = (cipher_block >> 40) & mask;
		cipher[ii+3] = (cipher_block >> 32) & mask;
		cipher[ii+4] = (cipher_block >> 24) & mask;
		cipher[ii+5] = (cipher_block >> 16) & mask;
		cipher[ii+6] = (cipher_block >> 8) & mask;
		cipher[ii+7] = (cipher_block) & mask;
	}
	//printf("%d ii = %d\n", strlen(cipher), ii);
	fwrite(cipher, 1, MAX_SIZE, out);
}

int main () {
	/*
	char key_buf[20];
	printf("Input hex key:\n");
	int i = 0;
	do {
		key_buf[i] = getchar();
		i++;
	} while(key_buf[i-1] != '\n');
	
	key_buf[i-1] = '\0';
	printf("%s\n", key_buf);
	main_key = atoi(key_buf, 16, 10);
	printf("%llX\n", main_key);
	return 0;*/

	time_t start, end;
	start = time(NULL);
	int i;

	main_key = 0x0101010101010101;	// default key

	int mode;
	char filename[32];
	printf("Select operating mode(0 -- e, 1 -- d):\n");
	scanf("%d", &mode);
	
	switch (mode) {
		case 0: generate_round_key_e(main_key); break;
		case 1: generate_round_key_d(main_key); break;
		default: printf("Wrong selection!!!"); return -1;
	}

	printf("Input filename:\n");
	scanf("%s", filename);
	in = fopen(filename, "rb");
	if (in == NULL) {
		printf("%s\n", "error");
		return -1;
	}
	printf("Processing...\n");

	// encryption
	if (mode == 0) {
		// store cipher
		out = fopen("zyx.dat", "wb");
		int size;
		
		while ( size = fread(buf, sizeof(char), MAX_SIZE, in) ) {
			
			if (size < MAX_SIZE) {
				for (i = size; i < MAX_SIZE; i++) {
					buf[i] = ' ';
				}
			}
			process_msg(buf);
		}
	}
	// decryption
	else {
		// store derypted file.
		out = fopen("result.dat", "wb");
		int size;
		
		while ( size = fread(buf, sizeof(char), MAX_SIZE, in) ) {
			// fill ' '.
			if (size < MAX_SIZE) {
				for (i = size; i < MAX_SIZE; i++) {
					buf[i] = ' ';
				}
			}
			process_msg(buf);
		}
	}

	fclose(in);
	fclose(out);

	end = time(NULL);
	printf("time = %.0f\n", difftime(end, start));

	return 0;
}


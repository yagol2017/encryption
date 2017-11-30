/*
	2017-11-16 12:00
	txt文件内字符的加密程序
	2017-11-19 20:06 一稿
*/

#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
//void encfile(char* in_filename, int code, char* out_filename);
//void decryptfile(char* in_filename_decrypt, int code, char* out_filename_decrypt);

class enc_decrypt {//基类
protected:
	char encfilename[999];
	char decryptfilename[999];
	int code;
public:
	void getname(char* name1, char* name2) {
		strcpy(encfilename, name1);//将name1复制到encfilename
		strcpy(decryptfilename, name2);//将name2复制到decrptfilename
	}
	void getcode(int code1) {
		code = code1;
	}

};
class enc :public enc_decrypt {//加密派生类
public:
	void encfile() {
		/*变量部分*/
		FILE *fp1;
		FILE *fp2;
		register char ch;
		/*变量部分*/
		fp1 = fopen(enc_decrypt::encfilename, "r");
		if (fp1 == NULL) {
			cout << "无法打开此文件" << endl;
			exit(1);
		}
		fp2 = fopen(enc_decrypt::decryptfilename, "w");
		if (fp2 == NULL) {
			cout << "无法打开或创建解密文件" << endl;
			exit(1);
		}
		/*开始加密*/
		ch = fgetc(fp1);
		while (!feof(fp1)) {
			//if (j0 > 7)
			//	j0 = 0;//每七次一循环，可以随时更改
			//ch += code[j0++];//也就是ch=ch+code【j0++】
			ch = ch + code;
			fputc(ch, fp2);
			ch = fgetc(fp1);
		}
		fclose(fp1);
		fclose(fp2);
	}
};

class decrypt :public enc_decrypt {
public:
	void decryptfile() {
		/*变量部分*/
		FILE *fp1;
		FILE *fp2;
		register char ch;
		/*变量部分*/
		fp1 = fopen(enc_decrypt::decryptfilename, "r");//需要解密的文件
		if (fp1 == NULL) {
			cout << "无法打开此文件" << endl;
			exit(1);
		}
		fp2 = fopen(enc_decrypt::encfilename, "w");//解密后文件
		if (fp2 == NULL) {
			cout << "无法打开或创建解密文件" << endl;
			exit(1);
		}
		/*开始解密*/
		ch = fgetc(fp1);
		while (!feof(fp1)) {
			//if (j0 > 7)
			//	j0 = 0;//每七次一循环，可以随时更改
			//ch += code[j0++];//也就是ch=ch+code【j0++】
			ch = ch - code;
			fputc(ch, fp2);
			ch = fgetc(fp1);
		}
		fclose(fp1);
		fclose(fp2);
	}
};


void main() {
	/*变量部分*/
	char in_filename_enc[999];//需要加密的文件名称（加密过程的变量）
	char out_filename_enc[999];//加密后文件名称（加密过程的变量）
	char in_filename_decrypt[999];//需要解密的文件名称（解密过程的变量）
	char out_filename_decrypt[999];//解密后文件名称（解密过程的变量）
	int code;//ASCII码加密子
	int option;//加密或解密选项控制
	/*变量部分*/

	cout << "txt文件内字符的加密与解密程序" << endl;
	//cout << "注意：请将文件放在与本程序同目录下" << endl;
	cout << "加密请输入 1 ，解密请输入 2 " << endl;
	cin >> option;
	switch (option) {
	case 1://加密部分
		enc enc;
		cout << "请输入要加密的文件名：" << endl;
		cin >> in_filename_enc;
		cout << "请输入加密后的文件名：" << endl;
		cin >> out_filename_enc;
		cout << "请输入加密子：" << endl;
		cin >> code;
		if (code < 0) {
			code = code*(-1);
		}
		if (code > 10) {
			code = code % 10;
		}
		enc.getname(in_filename_enc, out_filename_enc);
		enc.getcode(code);
		enc.encfile();
		/*encfile(in_filename_enc, code, out_filename_enc);*/
		break;
	case 2:
		decrypt decrypt;
		cout << "请输入要解密的文件名：" << endl;
		cin >> in_filename_decrypt;
		cout << "请输入解密后的文件名：" << endl;
		cin >> out_filename_decrypt;
		cout << "请输入加密子：（与加密时的加密子应相同）" << endl;
		cin >> code;
		if (code < 0) {
			code = code*(-1);
		}
		if (code > 10) {
			code = code % 10;
		}
		decrypt.getname(out_filename_decrypt,in_filename_decrypt);
		decrypt.getcode(code);
		decrypt.decryptfile();
		/*decryptfile(in_filename_decrypt, code, out_filename_decrypt);*/
		break;
	default:
		break;
	}

	cout << "感谢使用，谢谢" << endl;
}

//
//
//void encfile(char* in_filename, int code, char* out_filename) {
//	/*变量部分*/
//	FILE *fp1;
//	FILE *fp2;
//	register char ch;
//	/*变量部分*/
//	fp1 = fopen(in_filename, "r");
//	if (fp1 == NULL) {
//		cout << "无法打开此文件" << endl;
//		exit(1);
//	}
//	fp2 = fopen(out_filename, "w");
//	if (fp2 == NULL) {
//		cout << "无法打开或创建解密文件" << endl;
//		exit(1);
//	}
//	ch = fgetc(fp1);
//	/*开始加密*/
//	while (!feof(fp1)) {
//		//if (j0 > 7)
//		//	j0 = 0;//每七次一循环，可以随时更改
//		//ch += code[j0++];//也就是ch=ch+code【j0++】
//		ch = ch + code;
//		fputc(ch, fp2);
//		ch = fgetc(fp1);
//	}
//	fclose(fp1);
//	fclose(fp2);
//}
//
//
//void decryptfile(char* in_filename_decrypt, int code, char* out_filename_decrypt) {
//	/*变量部分*/
//	FILE *fp1;
//	FILE *fp2;
//	register char ch;
//	/*变量部分*/
//	fp1 = fopen(in_filename_decrypt, "r");
//	if (fp1 == NULL) {
//		cout << "无法打开此文件" << endl;
//		exit(1);
//	}
//	fp2 = fopen(out_filename_decrypt, "w");
//	if (fp2 == NULL) {
//		cout << "无法打开或创建解密文件" << endl;
//		exit(1);
//	}
//	ch = fgetc(fp1);
//	/*开始解密*/
//	while (!feof(fp1)) {
//		//if (j0 > 7)
//		//	j0 = 0;//每七次一循环，可以随时更改
//		//ch += code[j0++];//也就是ch=ch+code【j0++】
//		ch = ch - code;
//		fputc(ch, fp2);
//		ch = fgetc(fp1);
//	}
//	fclose(fp1);
//	fclose(fp2);
//}


#include"lastresult.h"
using namespace std;
using namespace boost;
bool key_match(string result_split, char* keywords) {


	
	regex pattern(keywords);
	cmatch key_result;
	string output;


	if (regex_search(result_split.c_str(), key_result, pattern)){
		return true;
	}
	else
		return false;
}
// (.*)(relative word)(.*)(relative word)(.*)
bool pattern_t(char* input, string pattern, char* keywords1, char* keywords2) {

	regex pattern_regex(pattern.c_str());  //����洢λ��
	cmatch result;//ƥ����

	string match_result1, match_result2, match_result3, match_result4, match_result5;

	if (!regex_match(input, result, pattern_regex)) {
		return false;
	}
	match_result1 = result[1];// storge the first (.*) contents
	match_result2 = result[2]; //storge the first relative word
	match_result3 = result[3]; //second (.*) contents
	match_result4 = result[4]; // secont relative word
	match_result5 = result[5]; // third(.*)contents
	/*//test code
	cout << "match_result1:" << match_result1 << endl;
	cout << "match_result2:" << match_result2 << endl;
	cout << "match_result3:" << match_result3 << endl;
	cout << "match_result4:" << match_result4 << endl;
	cout << "match_result5:" << match_result5 << endl;
	*/

	if (key_match(match_result1,keywords1)) { // match keyword1 in match_result
		if (key_match(match_result1, keywords2)) { // match keyword2 in match result
//			output = "\0";
			return false;

		}
		else if (key_match(match_result3, keywords2)) {
//			output = key_word1 + match_result2 + key_word2 + match_result4; // last result
			//   cout << "1    \n";  // test code
			return true;
		}
		else if (key_match(match_result5, keywords2))
		{
//			output = key_word1 + match_result2 + match_result4 + key_word2;
			//   cout << "2    \n";  //test code
			return true;
		}
		else {
//			output = "\0";
			return false;
		}
	}
	else if (key_match(match_result3, keywords1)) { //match keyword1 in match_result3
																		  //    cout <<  match_result3<<" dot1:"<<key_word1 << endl;  //test code
		if (key_match(match_result1,keywords2)) { // match keyword2 in match_result1
																		 //   cout << match_result1 <<"dot2:"<<key_word2 << endl; //test code
//			output = key_word2 + match_result2 + key_word1 + match_result4;
			//    cout << "3   \n"; // test code
			return true;
		}
		else if (key_match(match_result3, keywords2)) {
//			output = "\0";
			return false;
		}
		else if (key_match(match_result5, keywords2)) {
//			output = match_result2 + key_word1 + match_result4 + key_word2;
			//    cout << "4   \n";  //test code
			return true;
		}
		else {
//			output = "\0";
			return false;
		}
	}
	else if (key_match(match_result5, keywords1)) { //match keyword1 in match_result5
		if (key_match(match_result1, keywords2)) { // match keyword2 in match_result1
//			output = key_word2 + match_result2 + match_result4 + key_word1;
			//   cout << "5     \n";   //  test    code
			return true;
		}
		else if (key_match(match_result3, keywords2)) {
//			output = match_result2 + key_word2 + match_result4 + key_word1;
			//   cout << "6    \n";        //  test code
			return true;
		}
		else if (key_match(match_result5, keywords2)) {
//			output = "\0";
			return false;
		}
		else {
//			output = "\0";
			return false;
		}
	}
	else {
		return false;
	}
}
//(.*)(relative word)(.*)
bool pattern_o(char* input, string pattern, char* keywords1, char* keywords2) {
	string line = input;

	regex pattern_regex(pattern.c_str());
	cmatch result;

	string match_result1, match_result2, match_result3;

	if (!regex_match(input, result, pattern_regex)) {
		return false;
	}

	match_result1 = result[1]; // storge first(.*)contents
	match_result2 = result[2]; // storge relative word
	match_result3 = result[3]; //storge second (.*) contents

	if (key_match(match_result1, keywords1)) { // match keyword1 in match_result1
		if (key_match(match_result1, keywords2)) { // match keyword2 in match_result1
//			output = "\0";
			return false;
		}
		else if (key_match(match_result3, keywords2)) {
//			output = key_word1 + match_result2 + key_word2;
			return true;
		}
		else {
//			output = "\0";
			return false;
		}
	}
	else if (key_match(match_result3, keywords1)) {// match keyword1 in match_result3
		if (key_match(match_result1, keywords2)) { // match keyword2 in match_result1
//			output = key_word2 + match_result2 + key_word1;
			return true;
		}
		else if (key_match(match_result3, keywords2)) {
//			output = "\0";
			return false;
		}
		else {
//			output = "\0";
			return false;
		}
	}
	else {
//		output = "\0";
		return false;
	}
}
bool pattern_5_7(char* input, string pattern, char* keywords1, char* keywords2) {
	string line = input;

	regex pattern_regex(pattern);
	cmatch result;

	string match_result1, match_result2, match_result3;

	if (!regex_match(input, result, pattern_regex)) {
		return false;
	}

	match_result1 = result[1]; // storge first(.*)contents
	match_result2 = result[2]; // storge relative word
	match_result3 = result[3]; //storge second (.*) contents

	if (key_match(match_result2, keywords1)) { // match keyword1 in match_result1
		if (key_match(match_result2, keywords2)) { // match keyword2 in match_result1
			return true;
		}
		else if (key_match(match_result3, keywords2)) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (key_match(match_result3, keywords1)) {// match keyword1 in match_result3
		if (key_match(match_result2,keywords2)) { // match keyword2 in match_result1
			return true;
		}
		else if (key_match(match_result3, keywords2)) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}
int EVENT_GetRelation(char *sen, char* keywords1, char* keywords2, int* type)
{

	string line = sen; // �������char* ת��Ϊstring
	bool judge = false;
	*type = 0;
	string output; //�����ս���洢Ϊstring����
	string	pattern_but[] = { //ת�� 
		"(.*)(��Ȼ|����|��)(.*)(��Ҳ|����|��ȴ|��)(.*)",
		"(.*)(����)(.*)(����)(.*)",
		"(.*)(��Ȼ|����|��)(.*)(��|����Ҳ|���ǻ�|����ȴ)(.*)",
		"(.*)(����)(.*)(����)(.*)",
		"(.*)(��ʹ|������)(.*)(Ҳ|��)(.*)",
		"(.*)(����)(.*)(Ҳ|��)(.*)",
		"(.*)(��Ȼ|��ʹ)(.*)(����|����|Ȼ��|��Ȼ|����|Ҳ|��)(.*)",
		"(.*)(��Ȼ|����|��Ȼ)(.*)(Ҳ|��|ȴ)(.*)",
		"(.*)(����|����)(.*)(����|Ҳ��|ҲҪ)(.*)",
		"(.*)(����|����)(.*)(����|Ҳ��|ҲҪ)(.*)",
		"(.*)(����|��Ը)(.*)(Ҳ��|����|ҲҪ)(.*)",
		"(.*)(����|����|����|��ʹ)(.*)(��|Ҳ|��|ʼ��|һֱ)(.*)",
		"(.*)(��)(.*)(����|��|��|��|ȴ|����|����)(.*)",
		"(.*)(��Ȼ|��Ȼ|��ʹ)(.*)(��|����|����|��|����|��|ȴ)(.*)",
		"(.*)(��˵)(.*)(����|��|����|����|��|ȴ)(.*)",
		"(.*)(����)(.*)(��|Ҳ|��|��Ȼ|��|ʼ��|һֱ)(.*)",
		"(.*)(����)(.*)(����|����|����|��Ը)(.*)"
	};
	string	pattern_seq[] = {//˳cheng
		"(.*)(��|��|��|��)(.*)(����)(.*)",
		"(.*)(����|��һ)(.*)(���|Ȼ��)(.*)",
		"(.*)(����|����)(.*)(��|��|��|��)(.*)",
		"(.*)(һ����)(.*)(��һ����|��|Ҳ|��)(.*)"
	};
	string pattern_more[] = { // ����
		"(.*)(����|����)(.*)(����)(.*)",
		"(.*)(����)(.*)(����|����|Ҳ|��)(.*)",
		"(.*)(����)(.*)(����|����|Ҳ|��)(.*)",
		"(.*)(����)(.*)(��|Ҳ|��|ʼ��|һֱ)(.*)",
		"(.*)(����)(.*)(����|����|Ҳ|��)(.*)",
		"(.*)(��Ȼ|����)(.*)(����)(.*)",
		"(.*)(����)(.*)(��|����|����|Ҳ)(.*)",
		"(.*)(����)(.*)(����|Ҳ|��|��|ʼ��|һֱ)(.*)",
		"(.*)(��ֻ)(.*)(����|Ҳ|����|��)(.*)",
		"(.*)(����|����|����|��ֻ)(.*)(����)(.*)",
		"(.*)(����|��|Ҳ|��|��)(.*)(��|��)(.*)",
		"(.*)(��Ȼ|��)(.*)(��|��|��|��ô|Ҳ|��)(.*)",
		"(.*)(����|����|����|��)(.*)(����)(.*)",
		"(.*)(����)(.*)(����)(.*)",
		"(.*)(����|����|����|����)(.*)(����)(.*)",
		"(.*)(����)(.*)(Ҳ)(.*)",
		"(.*)(Ҫô|����)(.*)(Ҫô|����)(.*)"
	};
	string pattern_condition[] = { //����
		"(.*)(����)(.*)(����|��|��Ȼ|Ҫ��)(.*)",
		"(.*)(����)(.*)(����Ļ�)(.*)",
		"(.*)(����|����|����)(.*)(����|��|��)(.*)",
		"(.*)(��Ȼ)(.*)(��|��|Ҳ|��)(.*)",
		"(.*)(����)(.*)(��ô|��|Ҳ|��)(.*)",
		"(.*)(����|���)(.*)(��ô|��|��|��|��)(.*)",
		"(.*)(��ʹ|���)(.*)(��ô|��|��|��|��)(.*)",
		"(.*)(����|���)(.*)(��ô|��|��|��|��)(.*)",
		"(.*)(��ʹ|����)(.*)(Ҳ|����)(.*)",
		"(.*)(���|��Ȼ)(.*)(��ô)(.*)",
		"(.*)(��һ)(.*)(��ô|��)(.*)",
		"(.*)(Ҫ��|���)(.*)(��|��)(.*)",
		"(.*)(Ҫ��|���|����)(.*)(��ô|��|��|�Ļ�)(.*)",
		"(.*)(һ��)(.*)(��)(.*)",
		"(.*)(��Ȼ|����|��|���)(.*)(��|��)(.*)",
		"(.*)(ֻҪ)(.*)(��|��|��|��)(.*)",
		"(.*)(ֻ��)(.*)(��|��)(.*)"
	};
	string pattern_1[] = { // �ɹ���������ʽ
		"(.*)(֮?����)(.*)(��Ϊ)(.*)",
		"(.*)(֮?����)(.*)(����)(.*)",
		"(.*)(֮?����)(.*)(Ե��)(.*)"
	};
	string pattern_2[] = { //���򵽹�����ʽ
		"(.*)(��Ϊ)(.*)(�Ӷ�)(.*)",
		"(.*)(��Ϊ)(.*)(Ϊ��)(.*)",
		"(.*)(��Ȼ)(.*)(����)(.*)",
		"(.*)(����)(.*)(Ϊ��)(.*)",
		"(.*)(����)(.*)(��)(.*)",
		"(.*)(ֻ��)(.*)(��)(.*)",
		"(.*)(����)(,*)(������?)(.*)",
		"(.*)(��[Ȼ]?)(.*)(ȴ)(.*)",
		"(.*)(���)(.*)(��ô)(.*)",
		"(.*)(���)(.*)(��)(.*)",
		"(.*)(����)(.*)(�Ӷ�)(.*)",
		"(.*)(��Ȼ?)(.*)(���)(.*)",
		"(.*)(���)(.*)(��)(.*)",
		"(.*)(ֻҪ)(.*)(��)(.*)",
		"(.*)(��Ϊ)(.*)(����)(.*)",
		"(.*)(����)(.*)(����)(.*)",
		"(.*)(��Ϊ)(.*)(���)(.*)",
		"(.*)(����)(.*)(��)(.*)",
		"(.*)(��Ϊ)(.*)(������?)(.*)",
		"(.*)(��Ϊ)(.*)(���)(.*)",
		"(.*)(����)(.*)(���)(.*)",
		"(.*)(��Ϊ)(.*)(����)(.*)",
		"(.*)(����)(.*)(��ʹ)(.*)",
		"(.*)(��Ϊ)(.*)(��ʹ)(.*)",
		"(.*)(����)(.*)(������?)(.*)",
		"(.*)(��Ϊ)(.*)(��)(.*)",
		"(.*)(��[Ϊ]?)(.*)(������?)(.*)",
		"(.*)(����)(.*)(����)(.*)",
		"(.*)(��Ϊ)(.*)(�ʶ�)(.*)",
		"(.*)(����)(.*)(���)(.*)"
	};
	string pattern_3 = "(.*)[��|,]+.*(����|����|��|��ʹ|������?|���|������?|�Ӷ�|���)(.*)"; // ���򵽹�����ʽ��ȷ	
	string pattern_4[] = { //���򵽹�����ʽ��ȷ
		"(.*)(ǣ��|����|����|ʹ��|����|����|����|ָ��|ʹ|����|����|�ٳ�)(.*)",
		"(.*)(���|����|���|��ʹ|���|����|��͸|�ٽ�|����|�յ�|����|�ٷ�)(.*)",
		"(.*)(����|�շ�|�ƽ�|����|�ƶ�|����|Ӱ��|��ʹ|����|����|����|ʹ��)(.*)",
		"(.*)(����|����|����|����|��Ⱦ|����|Ю��|����|��ϵ|����|�ջ�|����|��ʹ)(.*)"
	};
	string pattern_5 = "(Ϊ��|����|����|��Ϊ|��|��|����|ƾ��|����)+(.*)[��|,]+(.*)";// ���򵽹�ǰ��ʽģ��
	string pattern_6 = "(.*)(����|�Ա�|Ϊ��|��)(.*)";// ���򵽹�����ʽģ��
	string pattern_7 = "(��Ȼ?|��|��Ϊ|���|����|ֻҪ)+(.*)[��|,]+(.*)";// ���򵽹�ǰ��ʽ��ȷ
	string pattern_8 = "(.*)(��Դ��|ȡ��|��Դ��|����|ȡ����|Ե��|����|����|��Դ��|����|��Դ��|����|Դ��|��Դ��|����|������)(.*)";
	// �ɹ��������ʽģ��
	string pattern_9 = "(.*)(��?��Ϊ|����)(.*)";// �ɹ�����Ӷ�ʽ��ȷ

	vector<string> pattern_but_temp(pattern_but, pattern_but + 17);
	for (vector<string>::iterator pattern = pattern_but_temp.begin(); pattern != pattern_but_temp.end(); ++pattern) //ת��ģʽƥ��
	{
		if (pattern_t(sen, *pattern, keywords1, keywords2))
		{
			*type = 1;
			judge = true;
			break;
		}
	}
	if (judge)
	{
		return 1;
	}
	vector<string> pattern_seq_temp(pattern_seq, pattern_seq + 4);
	for (vector<string>::iterator pattern = pattern_seq_temp.begin(); pattern != pattern_seq_temp.end(); ++pattern) //˳��ģʽƥ��
	{
		if (pattern_t(sen, *pattern, keywords1, keywords2))
		{
			*type = 2;
			judge = true;
			break;
		}
	}
	if (judge)
	{
		return 1;
	}
	vector<string> pattern_more_temp(pattern_more, pattern_more + 17);
	for (vector<string>::iterator pattern = pattern_more_temp.begin(); pattern != pattern_more_temp.end(); ++pattern) //����ģʽƥ��
	{
		if (pattern_t(sen, *pattern, keywords1, keywords2))
		{
			*type = 3;
			judge = true;
			break;
		}
	}
	if (judge)
	{
		return 1;
	}
	vector<string> pattern_condition_temp(pattern_condition, pattern_condition + 17);
	for (vector<string>::iterator pattern = pattern_condition_temp.begin(); pattern != pattern_condition_temp.end(); ++pattern) //����ģʽƥ��
	{
		if (pattern_t(sen, *pattern, keywords1, keywords2))
		{
			*type = 4;
			judge = true;
			break;
		}
	}
	if (judge)
	{
		return 1;
	}
	vector<string> pattern_1_temp(pattern_1, pattern_1 + 3);
	for (vector<string>::iterator pattern = pattern_1_temp.begin(); pattern != pattern_1_temp.end(); ++pattern) //�ɹ���������ʽ ģʽƥ��
	{
		if (pattern_t(sen, *pattern, keywords1, keywords2))
		{
			*type = 5;
			judge = true;
			break;
		}
	}
	if (judge)
	{
		return 1;
	}
	vector<string> pattern_2_temp(pattern_2, pattern_2 + 30);
	for (vector<string>::iterator pattern = pattern_2_temp.begin(); pattern != pattern_2_temp.end(); ++pattern) // ���򵽹�����ʽƥ��ģʽ
	{
		if (pattern_t(sen, *pattern, keywords1, keywords2))
		{
			*type = 6;
			judge = true;
			break;
		}
	}
	if (judge)
	{
		return 1;
	}
	if (pattern_o(sen, pattern_3, keywords1, keywords2))// ���򵽹�����ʽ��ȷƥ��ģʽ
		judge = true;
	if (judge)
	{
		*type = 6;
		return 1;
	}
	vector<string> pattern_4_temp(pattern_4, pattern_4 + 4);
	for (vector<string>::iterator pattern = pattern_4_temp.begin(); pattern != pattern_4_temp.end(); ++pattern) {
		if (pattern_o(sen, *pattern, keywords1, keywords2))//���򵽹�����ʽ��ȷƥ��ģʽ
		{
			*type = 6;
			judge = true;
			break;
		}
	}
	if (judge)
	{
		return 1;
	}
	if (pattern_5_7(sen, pattern_5, keywords1, keywords2))// ���򵽹�ǰ��ʽģ��ƥ��ģʽ
		judge = true;
	if (judge)
	{
		*type = 6;
		return 1;
	}
	if (pattern_o(sen, pattern_6, keywords1, keywords2)) //���򵽹�����ʽģ��ƥ��ģʽ
		judge = true;
	if (judge)
	{
		*type = 6;
		return 1;
	}
	if (pattern_5_7(sen, pattern_7, keywords1, keywords2)) // ���򵽹�ǰ��ʽ��ȷƥ��ģʽ
		judge = true;
	if (judge)
	{
		*type = 6;
		return 1;
	}
	if (pattern_o(sen, pattern_8, keywords1, keywords2)) //�ɹ��������ʽģ��ƥ��ģʽ
		judge = true;
	if (judge)
	{
		*type = 5;
		return 1;
	}
	if (pattern_o(sen, pattern_9, keywords1, keywords2)) //�ɹ�����Ӷ�ʽ��ȷƥ��ģʽ
		judge = true;
	if (judge)
	{
		*type = 5;
		return 1;
	}
	else
		return 0;
}


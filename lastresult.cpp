
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

	regex pattern_regex(pattern.c_str());  //正则存储位置
	cmatch result;//匹配结果

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

	string line = sen; // 将传入的char* 转换为string
	bool judge = false;
	*type = 0;
	string output; //将最终结果存储为string类型
	string	pattern_but[] = { //转折 
		"(.*)(虽然|尽管|虽)(.*)(但也|但还|但却|但)(.*)",
		"(.*)(与其)(.*)(不如)(.*)",
		"(.*)(虽然|尽管|虽)(.*)(但|但是也|但是还|但是却)(.*)",
		"(.*)(不是)(.*)(而是)(.*)",
		"(.*)(即使|就算是)(.*)(也|还)(.*)",
		"(.*)(即便)(.*)(也|还)(.*)",
		"(.*)(虽然|即使)(.*)(但是|可是|然而|仍然|还是|也|但)(.*)",
		"(.*)(虽然|尽管|固然)(.*)(也|还|却)(.*)",
		"(.*)(与其|宁可)(.*)(决不|也不|也要)(.*)",
		"(.*)(与其|宁肯)(.*)(决不|也不|也要)(.*)",
		"(.*)(与其|宁愿)(.*)(也不|决不|也要)(.*)",
		"(.*)(不管|不论|无论|即使)(.*)(都|也|总|始终|一直)(.*)",
		"(.*)(虽)(.*)(可是|倒|但|可|却|还是|但是)(.*)",
		"(.*)(虽然|纵然|即使)(.*)(倒|还是|但是|但|可是|可|却)(.*)",
		"(.*)(虽说)(.*)(还是|但|但是|可是|可|却)(.*)",
		"(.*)(无论)(.*)(都|也|还|仍然|总|始终|一直)(.*)",
		"(.*)(与其)(.*)(宁可|不如|宁肯|宁愿)(.*)"
	};
	string	pattern_seq[] = {//顺cheng
		"(.*)(又|再|才|并)(.*)(进而)(.*)",
		"(.*)(首先|第一)(.*)(其次|然后)(.*)",
		"(.*)(首先|先是)(.*)(再|又|还|才)(.*)",
		"(.*)(一方面)(.*)(另一方面|又|也|还)(.*)"
	};
	string pattern_more[] = { // 并列
		"(.*)(不但|不仅)(.*)(而且)(.*)",
		"(.*)(不单)(.*)(而且|并且|也|还)(.*)",
		"(.*)(不但)(.*)(而且|并且|也|还)(.*)",
		"(.*)(不管)(.*)(都|也|总|始终|一直)(.*)",
		"(.*)(不光)(.*)(而且|并且|也|还)(.*)",
		"(.*)(虽然|尽管)(.*)(不过)(.*)",
		"(.*)(不仅)(.*)(还|而且|并且|也)(.*)",
		"(.*)(不论)(.*)(还是|也|总|都|始终|一直)(.*)",
		"(.*)(不只)(.*)(而且|也|并且|还)(.*)",
		"(.*)(不但|不仅|不光|不只)(.*)(而且)(.*)",
		"(.*)(尚且|都|也|又|更)(.*)(还|又)(.*)",
		"(.*)(既然|既)(.*)(就|便|那|那么|也|还)(.*)",
		"(.*)(无论|不管|不论|或)(.*)(或者)(.*)",
		"(.*)(或是)(.*)(或是)(.*)",
		"(.*)(或者|不论|不管|不论)(.*)(或者)(.*)",
		"(.*)(不是)(.*)(也)(.*)",
		"(.*)(要么|或者)(.*)(要么|或者)(.*)"
	};
	string pattern_condition[] = { //条件
		"(.*)(除非)(.*)(否则|才|不然|要不)(.*)",
		"(.*)(除非)(.*)(否则的话)(.*)",
		"(.*)(还是|不论|不管)(.*)(还是|都|总)(.*)",
		"(.*)(既然)(.*)(又|且|也|亦)(.*)",
		"(.*)(假如)(.*)(那么|就|也|还)(.*)",
		"(.*)(假若|如果)(.*)(那么|就|那|则|便)(.*)",
		"(.*)(假使|如果)(.*)(那么|就|那|则|便)(.*)",
		"(.*)(尽管|如果)(.*)(那么|就|那|则|便)(.*)",
		"(.*)(即使|就是)(.*)(也|还是)(.*)",
		"(.*)(如果|既然)(.*)(那么)(.*)",
		"(.*)(万一)(.*)(那么|就)(.*)",
		"(.*)(要是|如果)(.*)(就|那)(.*)",
		"(.*)(要是|如果|假如)(.*)(那么|就|那|的话)(.*)",
		"(.*)(一旦)(.*)(就)(.*)",
		"(.*)(既然|假如|既|如果)(.*)(则|就)(.*)",
		"(.*)(只要)(.*)(就|便|都|总)(.*)",
		"(.*)(只有)(.*)(才|还)(.*)"
	};
	string pattern_1[] = { // 由果溯因配套式
		"(.*)(之?所以)(.*)(因为)(.*)",
		"(.*)(之?所以)(.*)(由于)(.*)",
		"(.*)(之?所以)(.*)(缘于)(.*)"
	};
	string pattern_2[] = { //由因到果配套式
		"(.*)(因为)(.*)(从而)(.*)",
		"(.*)(因为)(.*)(为此)(.*)",
		"(.*)(既然)(.*)(所以)(.*)",
		"(.*)(由于)(.*)(为此)(.*)",
		"(.*)(除非)(.*)(才)(.*)",
		"(.*)(只有)(.*)(才)(.*)",
		"(.*)(由于)(,*)(以至于?)(.*)",
		"(.*)(既[然]?)(.*)(却)(.*)",
		"(.*)(如果)(.*)(那么)(.*)",
		"(.*)(如果)(.*)(则)(.*)",
		"(.*)(由于)(.*)(从而)(.*)",
		"(.*)(既然?)(.*)(因此)(.*)",
		"(.*)(如果)(.*)(就)(.*)",
		"(.*)(只要)(.*)(就)(.*)",
		"(.*)(因为)(.*)(所以)(.*)",
		"(.*)(由于)(.*)(于是)(.*)",
		"(.*)(因为)(.*)(因此)(.*)",
		"(.*)(由于)(.*)(故)(.*)",
		"(.*)(因为)(.*)(以致于?)(.*)",
		"(.*)(因为)(.*)(因而)(.*)",
		"(.*)(由于)(.*)(因此)(.*)",
		"(.*)(因为)(.*)(于是)(.*)",
		"(.*)(由于)(.*)(致使)(.*)",
		"(.*)(因为)(.*)(致使)(.*)",
		"(.*)(由于)(.*)(以致于?)(.*)",
		"(.*)(因为)(.*)(故)(.*)",
		"(.*)(因[为]?)(.*)(以至于?)(.*)",
		"(.*)(由于)(.*)(所以)(.*)",
		"(.*)(因为)(.*)(故而)(.*)",
		"(.*)(由于)(.*)(因而)(.*)"
	};
	string pattern_3 = "(.*)[，|,]+.*(于是|所以|故|致使|以致于?|因此|以至于?|从而|因而)(.*)"; // 由因到果居中式明确	
	string pattern_4[] = { //由因到果居中式精确
		"(.*)(牵动|已致|导向|使动|导致|勾起|引入|指引|使|予以|产生|促成)(.*)",
		"(.*)(造成|引导|造就|促使|酿成|引发|渗透|促进|引起|诱导|引来|促发)(.*)",
		"(.*)(引致|诱发|推进|诱致|推动|招致|影响|致使|滋生|归于|作用|使得)(.*)",
		"(.*)(决定|攸关|令人|引出|浸染|带来|挟带|触发|关系|渗入|诱惑|波及|诱使)(.*)"
	};
	string pattern_5 = "(为了|依据|按照|因为|因|按|依赖|凭借|由于)+(.*)[，|,]+(.*)";// 由因到果前端式模糊
	string pattern_6 = "(.*)(以免|以便|为此|才)(.*)";// 由因到果居中式模糊
	string pattern_7 = "(既然?|因|因为|如果|由于|只要)+(.*)[，|,]+(.*)";// 由因到果前端式精确
	string pattern_8 = "(.*)(根源于|取决|来源于|出于|取决于|缘于|在于|出自|起源于|来自|发源于|发自|源于|根源于|立足|立足于)(.*)";
	// 由果溯因居中式模糊
	string pattern_9 = "(.*)(是?因为|由于)(.*)";// 由果溯因居端式精确

	vector<string> pattern_but_temp(pattern_but, pattern_but + 17);
	for (vector<string>::iterator pattern = pattern_but_temp.begin(); pattern != pattern_but_temp.end(); ++pattern) //转折模式匹配
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
	for (vector<string>::iterator pattern = pattern_seq_temp.begin(); pattern != pattern_seq_temp.end(); ++pattern) //顺承模式匹配
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
	for (vector<string>::iterator pattern = pattern_more_temp.begin(); pattern != pattern_more_temp.end(); ++pattern) //并列模式匹配
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
	for (vector<string>::iterator pattern = pattern_condition_temp.begin(); pattern != pattern_condition_temp.end(); ++pattern) //条件模式匹配
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
	for (vector<string>::iterator pattern = pattern_1_temp.begin(); pattern != pattern_1_temp.end(); ++pattern) //由果溯因配套式 模式匹配
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
	for (vector<string>::iterator pattern = pattern_2_temp.begin(); pattern != pattern_2_temp.end(); ++pattern) // 由因到果配套式匹配模式
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
	if (pattern_o(sen, pattern_3, keywords1, keywords2))// 由因到果居中式明确匹配模式
		judge = true;
	if (judge)
	{
		*type = 6;
		return 1;
	}
	vector<string> pattern_4_temp(pattern_4, pattern_4 + 4);
	for (vector<string>::iterator pattern = pattern_4_temp.begin(); pattern != pattern_4_temp.end(); ++pattern) {
		if (pattern_o(sen, *pattern, keywords1, keywords2))//由因到果居中式精确匹配模式
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
	if (pattern_5_7(sen, pattern_5, keywords1, keywords2))// 由因到果前端式模糊匹配模式
		judge = true;
	if (judge)
	{
		*type = 6;
		return 1;
	}
	if (pattern_o(sen, pattern_6, keywords1, keywords2)) //由因到果居中式模糊匹配模式
		judge = true;
	if (judge)
	{
		*type = 6;
		return 1;
	}
	if (pattern_5_7(sen, pattern_7, keywords1, keywords2)) // 由因到果前端式精确匹配模式
		judge = true;
	if (judge)
	{
		*type = 6;
		return 1;
	}
	if (pattern_o(sen, pattern_8, keywords1, keywords2)) //由果溯因居中式模糊匹配模式
		judge = true;
	if (judge)
	{
		*type = 5;
		return 1;
	}
	if (pattern_o(sen, pattern_9, keywords1, keywords2)) //由果溯因居端式精确匹配模式
		judge = true;
	if (judge)
	{
		*type = 5;
		return 1;
	}
	else
		return 0;
}


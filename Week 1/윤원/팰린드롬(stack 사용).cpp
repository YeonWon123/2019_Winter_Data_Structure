#include <iostream>
#include <string>
#include <stack>
using namespace std;

// 함수 원형
bool compPreAndPost(int start_idx, stack<char> pre, string input);
bool isPalindrome(string input);

/* main()함수에서 문장을 입력받습니다.
그리고 이를 isPalindrome()함수에 넘겨주어 해당 문장이 Palindrome인지 확인 합니다.
그리고 만약 맞으면 true를 출력하고 아니면 false를 출력하도록 했습니다.
*/

int main() {
	int n;
	cin >> n;
	cin.ignore();		// 버퍼를 비운다.

	for (int i = 0; i < n; i++) {
		string input;
		getline(cin, input);

		for (int j = 0; j < input.size(); j++)	// 대소문자 구분을 없애주기 위해서
			input[j] = toupper(input[j]);		// toupper를 사용하여 소문자->대문자로 변환한다.

		if (isPalindrome(input))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}

/*
cmpPreAndPost()함수는 int타입, stack 타입, string 타입을 input으로 하며, bool 타입을 output으로 하는 함수입니다. 
start_idx는 string타입의 input에서 post에 해당하는 알파벳의 시작 위치를 가리킵니다.
그리고 stack타입의 pre는 앞에서 정의했던 pre입니다. 
스택에 있는 pre와 input에 있는 post가 서로 역순이면 true, 그렇지 않으면 false를 리턴합니다.
여기서 좀 더 연산 시간을 단축시키기 위하여 비교과정에서 하나라도 어긋나면 
더이상의 비교는 무의미함으로 바로 false를 리턴하도록 구현하였습니다. 
그리고 stack을 pop할 때, memory access violation을 방지하기 위해 현재 스택이 비어있는지를 확인하는데 
사실, 로직상 이 부분은 생략하여도 됩니다. 그러나 안전장치로 마련해두었습니다.
*/

bool compPreAndPost(int start_idx, stack<char> pre, string input) {
	while (pre.size() != 0) {
		if (pre.top() != input[start_idx++])
			return false;
		else {
			if (!pre.empty())
				pre.pop();
		}
	}
	return true;
}

/*
isPalindrome()함수는 string타입의 input을 받고 bool타입을 output으로 하는 함수입니다.
이 함수에서는 넘겨받은 input이 Palindrome인지 확인합니다.
그리고 이 함수에서 위에서 언급되었던 1번 과정, pre, post를 나누는 과정을 진행합니다.
post는 시작 인덱스만 찾아내면 위치가 자명해지므로 별도로 저장하여 관리하진 않았습니다.

그리고 이를 cmpPreAndPost()로 넘겨주어 이 둘을 비교하고 이 둘이 서로 역순 관계계라면 true,
그렇지 않으면 false를 리턴하도록 하였습니다.
*/

bool isPalindrome(string input) {
	int inputLength = input.size();
	int start_idx;
	// input pre alphabet
	stack<char> pre;
	for (int i = 0; i < inputLength / 2; i++) {
		pre.push(input[i]);
	}

	// 만약 입력받은 문자열이 홀수일 경우, 시작지점은 inputlength / 2 이다.
	// if input length is even, then set starting index to input length
	if (inputLength % 2 == 0) {
		start_idx = inputLength / 2;
		if (compPreAndPost(start_idx, pre, input))
			return true;
		else
			return false;
	}

	// 만약 입력받은 문자열이 짝수일 경우, 시작지점은 inputlength + 1이다.
	// if input lengh is odd, then set starting index to input length + 1
	else {
		start_idx = inputLength / 2 + 1;
		if (compPreAndPost(start_idx, pre, input))
			return true;
		else
			return false;
	}
}


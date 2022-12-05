#include "17_02_regex.h"

#include <iostream>
#include <regex>
#include <vector>


/* Tech.) Pattern matching test using Regular Expression */
namespace RegExpPatternMatchTest {
	void simple_test() {
		std::vector<std::string> file_names = {
			"db-123-log.txt",
			"db-124-log.txt",
			"not-db-log.txt",
			"db-12-log.txt",
			"db-12-log.jpg"
		};

		std::regex regex_obj("db-\\d*-log\\.txt");
		for (const auto& file_name : file_names) {
			std::cout << file_name << " : " <<
				std::boolalpha << std::regex_match(file_name, regex_obj) << std::endl;
		}
	}
}

void regex_pattern_match_test() {
	RegExpPatternMatchTest::simple_test();
}


/* Tech.) Partial Pattern matching test using Regular Expression */
namespace RegExpPartialPatternMatchTest {
	void test() {
		std::vector<std::string> data = {
			"010-1234-5678", "010-123-4567",
			"011-1234-5567", "010-12345-6789",
			"123-4567-8901", "010-1234-567"
		};

		std::regex re("[01]{3}-\\d{3,4}-\\d{4}");
		for (const auto& number : data) {
			std::cout << number << " : " <<
				std::boolalpha << std::regex_match(number, re) << std::endl;
		}
	}

	void extract_part() {
		std::vector<std::string> data = {
			"010-1234-5678", "010-123-4567",
			"011-1234-5567", "010-12345-6789",
			"123-4567-8901", "010-1234-567"
		};

		std::regex re("[01]{3}-(\\d{3,4})-\\d{4}");		// Use parenthesis to specify the part that need to be extracted.
		
		std::smatch match;		// Store the matched result as an object.
		
		for (const auto& number : data) {
			if (std::regex_match(number, match, re)) {
				for (size_t i = 0; i < match.size(); i++) {
					std::cout << "Match : " << match[i].str() << std::endl;
				}
				std::cout << "-----------------------" << std::endl;
			}
		}

	}
}

void regex_partial_pattern_match_test() {
	RegExpPartialPatternMatchTest::test();
}

void regex_partial_extraction_test() {
	RegExpPartialPatternMatchTest::extract_part();
}


/* Tech.) Pattern Searching test using Regular Expression */
namespace RegExpSearchingTest {
	void test() {
		std::string html = R"(
        <div class="social-login">
          <div class="small-comment">다음으로 로그인 </div>
          <div>
            <i class="xi-facebook-official fb-login"></i>
            <i class="xi-google-plus goog-login"></i>
          </div>
        </div>
        <div class="manual">
          <div class="small-comment">
            또는 직접 입력하세요 (댓글 수정시 비밀번호가 필요합니다)
          </div>
          <input name="name" id="name" placeholder="이름">
          <input name="password" id="password" type="password" placeholder="비밀번호">
        </div>
        <div id="adding-comment" class="sk-fading-circle">
          <div class="sk-circle1 sk-circle">a</div>
          <div class="sk-circle2 sk-circle">b</div>
          <div class="sk-circle3 sk-circle">asd</div>
          <div class="sk-circle4 sk-circle">asdfasf</div>
          <div class="sk-circle5 sk-circle">123</div>
          <div class="sk-circle6 sk-circle">aax</div>
          <div class="sk-circle7 sk-circle">sxz</div>
        </div>)";

		std::regex re(R"(<div class="sk[\w -]*">\w*</div>)");
		std::smatch match;
		while (std::regex_search(html, match, re)) {
			std::cout << match.str() << std::endl;
			html = match.suffix();	// Returns std::sub_match object.
		}
	}
}

void regex_search_test() {
	RegExpSearchingTest::test();
}
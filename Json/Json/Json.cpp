// Json.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "json\json.h"

#pragma comment(lib,"json_vc71_libmtd.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
int main()
{		//1.从字符串解析json
	const char* str = "{\"uploadid\": \"UP000000\",\"code\": 100,\"msg\": \"\",\"files\": \"\"}";
	Json::Reader reader;
	Json::Value root;
	if (reader.parse(str, root))    // reader将Json字符串解析到root，root将包含Json里所有子元素  
	{
		printf("--------------从字符串读取JSON---------------\n");
		std::string upload_id = root["uploadid"].asString();  // 访问节点，upload_id = "UP000000"  
		int code = root["code"].asInt();                      // 访问节点，code = 100 

		printf("upload_id : %s\ncode : %d \n", upload_id.c_str(), code);
	}
    return 0;
}


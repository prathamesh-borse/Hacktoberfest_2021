import 'dart:convert';

import 'package:http/http.dart' as http;
import 'package:news_app/constants/strings.dart';
import 'package:news_app/models/news_info.dart';

class Api_Manager{

  Future<Welcome> getNews() async {
    var client = http.Client();
    var articleModel;
    try {
      var response = await client.get(Uri.parse(Strings.api_news_url));
      print(response.statusCode);
      if (response.statusCode == 200) {
        var jsonString = response.body;
        var jsonMap = json.decode(jsonString);
        articleModel = Welcome.fromJson(jsonMap);
      }
    }catch(Exception){
      return articleModel;
    }
    return articleModel;
  }
}
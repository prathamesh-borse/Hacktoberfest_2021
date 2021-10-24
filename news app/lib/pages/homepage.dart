import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:news_app/models/news_info.dart';
import 'package:news_app/services/api_manager.dart';

class Home extends StatefulWidget{
  @override
  _HomeState createState() => _HomeState();
}

class _HomeState extends State<Home>{
  Future<Welcome>? _articleModel;
  @override
  void initState(){
    _articleModel = Api_Manager().getNews();
    super.initState();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('News App'),
      ),
      body: Container(
        child:
              FutureBuilder<Welcome>(
                future: _articleModel,
                builder: (BuildContext context, AsyncSnapshot<Welcome> snapshot) {
                  if(snapshot.hasData){
                      itemCount: snapshot.data!.articles.length;
                      return ListView.builder(
                          itemBuilder: (context,index){
                            var article = snapshot.data!.articles[index];
                              return Container(
                                    height: 100,
                                    margin: const EdgeInsets.all(8),
                                    child: Row(
                                      children:
                                        <Widget>[
                                          Card(clipBehavior: Clip.antiAlias,
                                            shape: RoundedRectangleBorder(
                                              borderRadius: BorderRadius.circular(24),
                                            ),
                                            child: AspectRatio(
                                                aspectRatio: 1,
                                                child: Image.network(
                                                  article.urlToImage,
                                                  fit: BoxFit.cover,
                                                )),
                                          ),
                                            Flexible(
                                              child: Column(
                                                crossAxisAlignment: CrossAxisAlignment.end,
                                                children:<Widget>[
                                                  Text(
                                                    article.title,
                                                    overflow: TextOverflow.ellipsis,
                                                    style: TextStyle(
                                                      fontSize: 20,
                                                      fontWeight: FontWeight.bold
                                                    )
                                                  ),
                                                  Text(
                                                    article.description,
                                                    maxLines: 2,
                                                    // overflow: TextOverflow.ellipsis,
                                                    ),
                                                ],
                                              ),
                                            ),

                                        ],
                                    )
                              );
                      });
                  }else
                    return Center(child: CircularProgressIndicator(),);
                },
              ),
      ),
    );
  }
  
}
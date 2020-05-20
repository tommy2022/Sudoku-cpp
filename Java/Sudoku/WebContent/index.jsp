<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!-- Struts2のタグライブラリを使用可能にする -->
<%@ taglib prefix="s" uri="/struts-tags"%>
<!-- タイプ宣言はHTML5のものを使用する -->
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Struts2でHelloWorld</title>
    </head>
    <body>
        <!-- 入力フォームはStruts2のタグを使用します -->
        <s:form action="hello">
            <s:textfield name="name" />
            <s:radio label="Answer" name="yourAnswer" list="#{'1':'Yes','2':'No'}" value="2"/>
            <s:submit value="HelloWorldページへ行く" />
        </s:form>
        <s:form action="hello1">
            <s:textfield name="name1" />
            <s:submit value="HelloWorld1ページへ行く" />
        </s:form>
    </body>
</html>
<%@ Page Title="Домашняя страница" Language="C#" MasterPageFile="~/Site.master" AutoEventWireup="true"
    CodeBehind="Default.aspx.cs" Inherits="modelling._Default" %>

<asp:Content ID="HeaderContent" runat="server" ContentPlaceHolderID="HeadContent">
</asp:Content>
<asp:Content ID="BodyContent" runat="server" ContentPlaceHolderID="MainContent">
    <h2>
        Добро пожаловать в ASP.NET!
    </h2>
    <p>
        Для получения дополнительных сведений об ASP.NET посетите веб-сайт <a href="http://www.asp.net" title="Веб-сайт ASP.NET">www.asp.net</a>.
    </p>
    <p>
        Кроме того, <a href="http://go.microsoft.com/fwlink/?LinkID=152368"
            title="Документация по ASP.NET на MSDN">документация по ASP.NET доступна на MSDN</a>.
    </p>
    <div id="d">
    
    </div>

    <p>
        <asp:TextBox ID="username" runat="server"></asp:TextBox>

        <asp:TextBox ID="password" runat="server"></asp:TextBox>
        <asp:Button ID="Button1" runat="server" OnClick="btn1_click" Text="Button" />
        <asp:Label ID="Label1" runat="server" Text="Label"></asp:Label>
        
    </p>
</asp:Content>

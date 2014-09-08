<%@ Page Title="Регистрация" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Registration.aspx.cs" Inherits="modelling.WebForm1" %>
<asp:Content ID="HeaderContent" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>
<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">
    <p>Регистрация нового пользователя</p>
    <div id="newUserRegistrationContainer"> 
    <div style="width:90%;"><asp:Label ID="regMessage" Text="" runat=server></asp:Label></div>
        <asp:LoginView ID="registrationView" runat=server>
            <LoggedInTemplate>
                <p class="attentionMessage">Вы уже авторизованы на сайте! <br /> Необходимо выйти из системы для регистрации. </p>
            </LoggedInTemplate>
            <AnonymousTemplate>
                
                  <div>
                  Логин: <br />
                       Пароль:  <br />
                   Подтвердите пароль: <br />
               
                   Электронная почта: <br />
                    Имя: <br />
                   Фамилия: <br />
                    Контактный телефон: <br />
                </div>
                <div>
                <asp:TextBox CssClass="regTextBox" runat=server MaxLength=20  ID=regLogin  ></asp:TextBox> <br />
                <asp:TextBox runat=server CssClass="regTextBox" MaxLength=20 TextMode=Password ID=regPassword  ></asp:TextBox> <br />
                <asp:TextBox runat=server CssClass="regTextBox" TextMode=Password MaxLength=20  ID=PasswordConfirm  ></asp:TextBox> <br />
                <asp:TextBox runat=server CssClass="regTextBox" TextMode=Email MaxLength=20 ID=regMail  ></asp:TextBox><br />
                <asp:TextBox runat=server CssClass="regTextBox" MaxLength=20  ID=regName  ></asp:TextBox> <br />
                <asp:TextBox runat=server CssClass="regTextBox" MaxLength=20  ID=regFamily ></asp:TextBox> <br />
                   <asp:TextBox runat=server CssClass="regTextBox"  TextMode=Phone ID=regPhone ></asp:TextBox> <br />
                </div>

                <div style="width:90%;"><asp:Button ID=sendReg OnClick="sendReg_click" runat=server Text="Зарегистрировать!"/> </div>
            </AnonymousTemplate>
        </asp:LoginView>
    </div>
</asp:Content>

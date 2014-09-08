<%@ Page Title="Смена пароля" Language="C#" MasterPageFile="~/Site.master" AutoEventWireup="true"
    CodeBehind="ChangePassword.aspx.cs" Inherits="modelling.Account.ChangePassword" %>

<asp:Content ID="HeaderContent" runat="server" ContentPlaceHolderID="HeadContent">
</asp:Content>
<asp:Content ID="BodyContent" runat="server" ContentPlaceHolderID="MainContent">
    <h2>
        Смена пароля
    </h2>
    <p>
        Используйте следующую форму для смены своего пароля.
    </p>
    <p>
        Длина нового пароля не должна быть меньше <%= Membership.MinRequiredPasswordLength %> знаков.
    </p>
    <asp:ChangePassword ID="ChangeUserPassword" runat="server" CancelDestinationPageUrl="~/" EnableViewState="false" RenderOuterTable="false" 
         SuccessPageUrl="ChangePasswordSuccess.aspx">
        <ChangePasswordTemplate>
            <span class="failureNotification">
                <asp:Literal ID="FailureText" runat="server"></asp:Literal>
            </span>
            <asp:ValidationSummary ID="ChangeUserPasswordValidationSummary" runat="server" CssClass="failureNotification" 
                 ValidationGroup="ChangeUserPasswordValidationGroup"/>
            <div class="accountInfo">
                <fieldset class="changePassword">
                    <legend>Сведения учетной записи</legend>
                    <p>
                        <asp:Label ID="CurrentPasswordLabel" runat="server" AssociatedControlID="CurrentPassword">Старый пароль:</asp:Label>
                        <asp:TextBox ID="CurrentPassword" runat="server" CssClass="passwordEntry" TextMode="Password"></asp:TextBox>
                        <asp:RequiredFieldValidator ID="CurrentPasswordRequired" runat="server" ControlToValidate="CurrentPassword" 
                             CssClass="failureNotification" ErrorMessage="Поле ''Пароль'' является обязательным." ToolTip="Поле ''Старый пароль'' является обязательным." 
                             ValidationGroup="ChangeUserPasswordValidationGroup">*</asp:RequiredFieldValidator>
                    </p>
                    <p>
                        <asp:Label ID="NewPasswordLabel" runat="server" AssociatedControlID="NewPassword">Новый пароль:</asp:Label>
                        <asp:TextBox ID="NewPassword" runat="server" CssClass="passwordEntry" TextMode="Password"></asp:TextBox>
                        <asp:RequiredFieldValidator ID="NewPasswordRequired" runat="server" ControlToValidate="NewPassword" 
                             CssClass="failureNotification" ErrorMessage="Поле ''Новый пароль'' является обязательным." ToolTip="Поле ''Новый пароль'' является обязательным." 
                             ValidationGroup="ChangeUserPasswordValidationGroup">*</asp:RequiredFieldValidator>
                    </p>
                    <p>
                        <asp:Label ID="ConfirmNewPasswordLabel" runat="server" AssociatedControlID="ConfirmNewPassword">Подтвердите новый пароль:</asp:Label>
                        <asp:TextBox ID="ConfirmNewPassword" runat="server" CssClass="passwordEntry" TextMode="Password"></asp:TextBox>
                        <asp:RequiredFieldValidator ID="ConfirmNewPasswordRequired" runat="server" ControlToValidate="ConfirmNewPassword" 
                             CssClass="failureNotification" Display="Dynamic" ErrorMessage="Поле ''Подтвердите новый пароль'' обязательно."
                             ToolTip="Поле ''Подтвердите новый пароль'' обязательно." ValidationGroup="ChangeUserPasswordValidationGroup">*</asp:RequiredFieldValidator>
                        <asp:CompareValidator ID="NewPasswordCompare" runat="server" ControlToCompare="NewPassword" ControlToValidate="ConfirmNewPassword" 
                             CssClass="failureNotification" Display="Dynamic" ErrorMessage="Значение ''Подтвердите новый пароль'' должно совпадать со значением ''Новый пароль''."
                             ValidationGroup="ChangeUserPasswordValidationGroup">*</asp:CompareValidator>
                    </p>
                </fieldset>
                <p class="submitButton">
                    <asp:Button ID="CancelPushButton" runat="server" CausesValidation="False" CommandName="Cancel" Text="Отмена"/>
                    <asp:Button ID="ChangePasswordPushButton" runat="server" CommandName="ChangePassword" Text="Смена пароля" 
                         ValidationGroup="ChangeUserPasswordValidationGroup"/>
                </p>
            </div>
        </ChangePasswordTemplate>
    </asp:ChangePassword>
</asp:Content>

using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;

namespace modelling
{
    public partial class WebForm1 : MyPage
    {
       
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void sendReg_click(object sender, EventArgs e)
        {
            SqlCommand command = new SqlCommand();
            command=baseConnect();
            SqlDataReader reader;
            command.CommandText = "select count(*) from usr where login='" + 
                ((TextBox)registrationView.FindControl("regLogin")).Text+"';";
            reader = command.ExecuteReader();
            reader.Read();
            if ((int)reader.GetValue(0) != 0)
            {
                regMessage.Text = "Пользователь с таким логином уже существует!";
                reader.Close();
                return;
            }
            
            command.CommandText = "insert into usr(login,password,mail,name,family,phone) values('"+
                ((TextBox)registrationView.FindControl("regLogin")).Text+"','"+
                ((TextBox)registrationView.FindControl("regPassword")).Text + "','"+
                ((TextBox)registrationView.FindControl("regmail")).Text+"','"+
                ((TextBox)registrationView.FindControl("regName")).Text+"','"+
                ((TextBox)registrationView.FindControl("regfamily")).Text+"','"+
                ((TextBox)registrationView.FindControl("regphone")).Text + "');"
                ;
            command.ExecuteNonQuery();
            registrationView.Visible = false;
            regMessage.Text = "На указанную Вами почту выслано письмо подтверждения регистрации. <a href=default.aspx>Возврат на главную.</a>"; 
            // .Text = "На указанную Вами почту выслано письмо подтверждения регистрации ";
            return;
        }
    }
}
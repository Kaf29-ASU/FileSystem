using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Web.Security;
using System.Security.Cryptography;

namespace modelling
{
   
    public partial class SiteMaster : System.Web.UI.MasterPage 
    {
        
        protected void EnterTheSystem(object sender, EventArgs e)
        {
            SqlConnection c = new SqlConnection();
            SqlCommand q = new SqlCommand();
            c.ConnectionString = @"Data Source=.\SQLEXPRESS;AttachDbFilename=C:\Users\Андрей\Documents\Visual Studio 2010\Projects\modelling\modelling\App_Data\Database1.mdf;Integrated Security=True;User Instance=True";
            c.Open();
            q.Connection = c;
            TextBox t = ((TextBox)HeadLoginView.FindControl("loginUsrName"));
            q.CommandText = "select password from usr where login='" + ((TextBox)HeadLoginView.FindControl("loginUsrName")).Text + "';";
            SqlDataReader r;
            r = q.ExecuteReader();
            if (!(r.Read()))
            {
                ((Label)HeadLoginView.FindControl("authInfo")).ForeColor = System.Drawing.Color.Red;
                ((Label)HeadLoginView.FindControl("authInfo")).Text = "Неверная пара логин/пароль! Повторите ввод.";
                return;
            }
            if (((string)r.GetValue(0)) ==  ((TextBox)HeadLoginView.FindControl("loginPassword")).Text)
            {
                FormsAuthentication.SetAuthCookie(((TextBox)HeadLoginView.FindControl("loginUsrName")).Text, false);
                FormsAuthentication.RedirectFromLoginPage(((TextBox)HeadLoginView.FindControl("loginUsrName")).Text, false);
                c.Close();
                
                
                //HeadLoginView.ViewStateMode =
                return;
            }
            ((Label)HeadLoginView.FindControl("authInfo")).ForeColor = System.Drawing.Color.Red;
            ((Label)HeadLoginView.FindControl("authInfo")).Text = "Неверная пара логин/пароль! Повторите ввод.";


        }


        protected void Page_Load(object sender, EventArgs e)
        {

           
            /*qlConnection conn=new SqlConnection();
            conn.ConnectionString = "Data Source=SQLEXPRESS;AttachDbFilename=Database1.mdf;Integrated Security=True;User Instance=True";
            conn.Open();
            SqlCommand con = new SqlCommand();
            con.Connection = conn;
            con.CommandText = "insert into usr(login,password,mail,name,family,phone) values('1','2','3','4','5','6');";
            con.ExecuteNonQuery();*/
        }

       
    }
}

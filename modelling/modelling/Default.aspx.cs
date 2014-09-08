using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;


namespace modelling
{
    public partial class _Default : MyPage
    {
        protected void Page_Load(object sender, EventArgs e)
        {
           
        }

        protected void btn1_click(object sender, EventArgs e)
        {
            Label1.Text = "";
            SqlConnection c = new SqlConnection();
            SqlCommand q = new SqlCommand();
            
            c.ConnectionString = @"Data Source=.\SQLEXPRESS;AttachDbFilename=C:\Users\Андрей\Documents\Visual Studio 2010\Projects\modelling\modelling\App_Data\Database1.mdf;Integrated Security=True;User Instance=True";
            c.Open();
            q.Connection = c;
            q.CommandText = "insert into usr(login,password,mail,name)"+
                " values('"+username.Text+"','"+password.Text+"','asd','zxcv')";
            q.ExecuteNonQuery();
           q.CommandText = "select * from usr;";
           SqlDataReader r;
           r = q.ExecuteReader();
            
           while (r.Read())
           {
               Label1.Text += r.GetValue(1) + " " + r.GetValue(2) + "<br>";
           }
           c.Close();
        }
    }
}

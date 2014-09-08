using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data.SqlClient;
using System.Web.Security;
using System.Web.UI.WebControls;
using System.Web.UI;


namespace modelling
{
    public partial class MyPage : Page
    {

        public SqlCommand baseConnect()
        {
            SqlConnection c = new SqlConnection();
            SqlCommand q = new SqlCommand();
            c.ConnectionString = @"Data Source=.\SQLEXPRESS;AttachDbFilename=C:\Users\Андрей\Documents\Visual Studio 2010\Projects\modelling\modelling\App_Data\Database1.mdf;Integrated Security=True;User Instance=True";
            c.Open();
            q.Connection = c;
            return q;
        }

    }
}
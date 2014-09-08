using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.SessionState;
using System.Data.SqlClient;

namespace modelling
{

    public class Global : System.Web.HttpApplication
    {
        
        void Application_Start(object sender, EventArgs e)
        {
            
        }

        void Application_End(object sender, EventArgs e)
        {
            //  Код, выполняемый при завершении работы приложения

        }

        void Application_Error(object sender, EventArgs e)
        {
            // Код, выполняемый при возникновении необрабатываемой ошибки

        }

        void Session_Start(object sender, EventArgs e)
        {
            // Код, выполняемый при запуске нового сеанса

        }

        void Session_End(object sender, EventArgs e)
        {
            // Код, выполняемый при запуске приложения. 
            // Примечание: Событие Session_End вызывается только в том случае, если для режима sessionstate
            // задано значение InProc в файле Web.config. Если для режима сеанса задано значение StateServer 
            // или SQLServer, событие не порождается.

        }

    }
}

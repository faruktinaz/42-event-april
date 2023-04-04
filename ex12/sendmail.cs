using	System.Net;
using	System.Net.Mail;

namespace	SendMail
{
	class Program
	{
		static string smtpAdress = "smtp.gmail.com";
		static int portNumber = 587;
		static bool enableSSL = true;
		static string emailFromAddress = "--your email--";
		static string password = "--your mail app passw--";
		static string emailToAdress = "example@gmail.com";
		static string subject = "Faruk Tinaz";
		static string body = "test message sent.";
		static void Main(string[] args)
		{
			SendEmail();
		}
		public static void SendEmail()
		{
			using(MailMessage mail = new MailMessage())
			{
				mail.From = new MailAddress(emailFromAddress);
				mail.To.Add(emailToAdress);
				mail.Subject = subject;
				mail.Body = body;
				mail.IsBodyHtml = true;
				using (SmtpClient smtp = new SmtpClient(smtpAdress, portNumber))
				{
					smtp.Credentials = new NetworkCredential(emailFromAddress, password);
					smtp.EnableSsl = enableSSL;
					smtp.Send(mail);
				}
			}
		}
	}
}
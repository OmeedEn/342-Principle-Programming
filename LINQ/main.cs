using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Xml.Linq;

class Program
{
    public static void Main(string[] args)
    {
        if (args.Length != 2)
        {
            Console.WriteLine("Usage: FileReportGenerator <inputFolderPath> <outputHtmlFilePath>");
            return;
        }

        string inputFolderPath = args[0];
        string outputHtmlFilePath = args[1];

        IEnumerable<string> files = EnumerateFilesRecursively(inputFolderPath);
        XDocument report = CreateReport(files);

        report.Save(outputHtmlFilePath);

        Console.WriteLine($"Report generated and saved to: {outputHtmlFilePath}");
    }

    static IEnumerable<string> EnumerateFilesRecursively(string path)
    {
        foreach (var filePath in Directory.EnumerateFiles(path, "*", SearchOption.AllDirectories))
        {
            yield return filePath;
        }
    }

    static string FormatByteSize(long byteSize)
    {
        string[] sizeSuffixes = { "B", "kB", "MB", "GB", "TB", "PB", "EB", "ZB" };

        int index = 0;
        double size = byteSize;

        while (size >= 1000 && index < sizeSuffixes.Length - 1)
        {
            size /= 1000;
            index++;
        }

        return $"{size:F2}{sizeSuffixes[index]}";
    }

    static XDocument CreateReport(IEnumerable<string> files)
    {
        var fileGroups = files
            .Select(filePath => new FileInfo(filePath))
            .GroupBy(fileInfo => fileInfo.Extension.ToLower())
            .OrderByDescending(group => group.Sum(fileInfo => fileInfo.Length));

        var htmlReport = new XDocument(
            new XDocumentType("html", null, null, null),
            new XElement("html",
                new XElement("head",
                    new XElement("title", "File Report")
                ),
                new XElement("body",
                    new XElement("h1", "File Report"),
                    new XElement("table",
                        new XElement("tr",
                            new XElement("th", "Type"),
                            new XElement("th", "Count"),
                            new XElement("th", "Size")
                        ),
                        from group in fileGroups
                        select new XElement("tr",
                            new XElement("td", group.Key),
                            new XElement("td", group.Count()),
                            new XElement("td", FormatByteSize(group.Sum(fileInfo => fileInfo.Length)))
                        )
                    )
                )
            )
        );//.Save("path, report.html");

        return htmlReport;
    }
}


// using System;
// using System.IO; //allows us to use the Directory class
// using System.Collections.Generic; // allows us to use the IEnumerable interface
// using System.Linq; // allows us to create LINQ queries
// using System.Text;

// class Program
// {
//     public static void Main(String[] args)
//     {
//         string folderpath = args[0].ToLower();
//         string HTMLreport = args[1].ToLower();

//         var files = EnumerateFilesRecursively(folderpath);
//         var report = CreateReport(files);
//         files.WriteAllText(HTMLreport, report);
//         Console.WriteLine("Hello World");
//     }
//     static IEnumerable<string> EnumerateFilesRecursively(string path)
//     { //has to be in lazy way
//         var dirs = from dir in // start of Linq query
//          Directory.EnumerateDirectories(path, "*",
//             SearchOption.AllDirectories) //searchOption guarantees that all subdirectories are searched
//                    select dir;
//         yield return dirs.ToString();

//     }
//     static string FormatByteSize(long byteSize)
//     {
//         string[] units = { "B", "kB", "MB", "GB", "TB", "PB", "EB", "ZB" };
//         double val;
//         while (val >= 0 && val < 1000)
//         {
//             byteSize = 1000;

//         }
//         yield return $"{byteSize.ToString("#.##")}{units[val]}";
//     }

//     static XDocument CreateReport(IEnumerable<string> files)
//     {

//         var sizes = [];
//         foreach (var file in files):
//     {
//             var sizes.add(System.IO.FileInfo) //finds the size of the files
//     }

//         var htmlBuilder = new StringBuider();
//         htmlBuilder.Add("<head>");
//         htmlBuilder.Add("<title>Html Output Table</title>");
//         htmlBuilder.Add("</head>");
//         htmlBuilder.Add("<body>");
//         htmlBuilder.Add("<table border=\"1\">");
//         htmlBuilder.Add("<tr><th>Type</th><th>Count</th><th>Size (bytes)</th></tr>");

//         // Add rows to the table for each file group
//         foreach (var group in fileGroups) //declare fileGroups
//         {
//             htmlBuilder.Add("<tr>");
//             htmlBuilder.Add($"<td>{group.Type}</td>");
//             htmlBuilder.Add($"<td>{group.Count}</td>");
//             htmlBuilder.Add($"<td>{group.Size}</td>");
//             htmlBuilder.Add("</tr>");
//         }

//         htmlBuilder.Add("</table>");
//         htmlBuilder.Add("</body>");
//         htmlBuilder.Add("</html>");

//         File.WriteAllText(//path) 
//   }

// }
// //output has to be sorted by size of the file
// //how many files with specific extension and sorted by size, and calculate total size of all 

// //create helper function to create table

// //enumerate files 

// using System;
// using System.Collections.Generic;
// using System.IO;
// using System.Linq;
// using System.Xml.Linq;

// class Program
// {
//     public static void Main(string[] args)
//     {
//         if (args.Length != 2)
//         {
//             Console.WriteLine("Usage: FileReportGenerator <inputFolderPath> <outputHtmlFilePath>");
//             return;
//         }

//         string inputFolderPath = args[0];
//         string outputHtmlFilePath = args[1];

//         IEnumerable<string> files = EnumerateFilesRecursively(inputFolderPath);
//         XDocument report = CreateReport(files);

//         report.Save(outputHtmlFilePath);

//         Console.WriteLine($"Report generated and saved to: {outputHtmlFilePath}");
//     }

//     static IEnumerable<string> EnumerateFilesRecursively(string path)
//     {
//         foreach (var filePath in Directory.EnumerateFiles(path, "*", SearchOption.AllDirectories))
//         {
//             yield return filePath;
//         }
//     }

//     static string FormatByteSize(long byteSize)
//     {
//         string[] sizeSuffixes = { "B", "kB", "MB", "GB", "TB", "PB", "EB", "ZB" };

//         int index = 0;
//         double size = byteSize;

//         while (size >= 1000 && index < sizeSuffixes.Length - 1)
//         {
//             size /= 1000;
//             index++;
//         }

//         return $"{size:F2}{sizeSuffixes[index]}";
//     }

//     static XDocument CreateReport(IEnumerable<string> files)
//     {
//         var fileGroups = files
//             .Select(filePath => new FileInfo(filePath))
//             .GroupBy(fileInfo => fileInfo.Extension.ToLower())
//             .OrderByDescending(group => group.Sum(fileInfo => fileInfo.Length));

//         var htmlReport = new XDocument(
//             new XDocumentType("html", null, null, null),
//             new XElement("html",
//                 new XElement("head",
//                     new XElement("title", "File Report")
//                 ),
//                 new XElement("body",
//                     new XElement("h1", "File Report"),
//                     new XElement("table",
//                         new XElement("tr",
//                             new XElement("th", "Type"),
//                             new XElement("th", "Count"),
//                             new XElement("th", "Size")
//                         ),
//                         from group in fileGroups
//                         select new XElement("tr",
//                             new XElement("td", group.Key),
//                             new XElement("td", group.Count()),
//                             new XElement("td", FormatByteSize(group.Sum(fileInfo => fileInfo.Length)))
//                         )
//                     )
//                 )
//             )
//         );//.Save("path, report.html");

//         return htmlReport;
//     }
// }

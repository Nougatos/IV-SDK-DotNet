﻿using System;
using System.Diagnostics;
using System.IO;
using System.Runtime.InteropServices;

namespace Manager {
    internal class Helper {

        #region Classes
        /// <summary>
        /// Some helper functions in use with <see cref="Process"/>.
        /// </summary>
        public class ProcessHelper {

            #region DllImports
            [DllImport("user32.dll")]
            [return: MarshalAs(UnmanagedType.Bool)]
            private static extern bool GetWindowPlacement(IntPtr hWnd, ref WINDOWPLACEMENT lpwndpl);

            [DllImport("user32.dll", CharSet = CharSet.Auto, ExactSpelling = true)]
            private static extern IntPtr GetForegroundWindow();


            [DllImport("user32.dll", CharSet = CharSet.Auto, SetLastError = true)]
            private static extern int GetWindowThreadProcessId(IntPtr handle, out int processId);
            #endregion

            #region Structs
            private struct WINDOWPLACEMENT {
                public int length;
                public int flags;
                public int showCmd;
                public System.Drawing.Point ptMinPosition;
                public System.Drawing.Point ptMaxPosition;
                public System.Drawing.Rectangle rcNormalPosition;
            }
            #endregion

            /// <summary>
            /// Gets the current window state of the given <see cref="Process"/>.
            /// </summary>
            /// <param name="p">Target <see cref="Process"/>.</param>
            /// <returns>
            /// -1 : MainWindowHandle of given <see cref="Process"/> is null.<br/>
            /// 1  : <see cref="Process"/> Window is <b>Normalized</b>.<br/>
            /// 2  : <see cref="Process"/> Window is <b>Minimized</b>.<br/>
            /// 3  : <see cref="Process"/> Window is <b>Maximized</b>.
            /// </returns>
            public static int GetProcessWindowState(Process p)
            {
                if (p.MainWindowHandle != IntPtr.Zero) {
                    WINDOWPLACEMENT placement = new WINDOWPLACEMENT();
                    GetWindowPlacement(p.MainWindowHandle, ref placement);
                    return placement.showCmd;
                }
                return -1;
            }

            /// <summary>
            /// Gets if the given <see cref="Process"/> has focus.
            /// </summary>
            /// <param name="p">Target <see cref="Process"/>.</param>
            /// <returns>True if the <see cref="Process"/> is in focus, otherwise false.</returns>
            public static bool IsProcessInFocus(Process p)
            {
                var activatedHandle = GetForegroundWindow();
                if (activatedHandle == IntPtr.Zero) {
                    return false; // No window is currently activated
                }

                int procId = p.Id;
                int activeProcId;
                GetWindowThreadProcessId(activatedHandle, out activeProcId);

                return activeProcId == procId;
            }

        }
        #endregion

        public static byte[] GetByteArray(Stream input)
        {
            using (MemoryStream ms = new MemoryStream()) {
                input.CopyTo(ms);
                return ms.ToArray();
            }
        }

    }
}

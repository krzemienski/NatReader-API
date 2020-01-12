/* 
*   NatReader
*   Copyright (c) 2020 Yusuf Olokoba.
*/

namespace NatReader {

    using System;
    using System.Collections.Generic;

    /// <summary>
    /// A reader capable of reading media frames from a media input.
    /// All recorder methods are thread safe, and as such can be called from any thread.
    /// </summary>
    public interface IMediaReader <T> : IEnumerable<T>, IDisposable {

        /// <summary>
        /// Media source URI.
        /// </summary>
        string uri { get; }

        /// <summary>
        /// Media duration in seconds.
        /// </summary>
        float duration { get; }
    }
}
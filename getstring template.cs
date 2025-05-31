public static string thermo3_getName(ThermoPhaseHandle handle)
    {
        Span<byte> buffer = stackalloc byte[360];

        // try with stack-allocated buffer
        var neededSize = Math.Abs(_thermo3_getName(handle, 360, buffer));
        if (neededSize <= 360)
        {
            return Encoding.UTF8.GetString(buffer[..(neededSize - 1)]);
        }

        // try with rented array buffer
        byte[] array = null;
        try
        {
            array = ArrayPool<byte>.Shared.Rent(neededSize);
            neededSize = Math.Abs(_thermo3_getName(handle, array.Length, array));
            if (neededSize <= array.Length)
            {
                return Encoding.UTF8.GetString(array, 0, neededSize - 1);
            }
        }
        finally
        {
            if (array is not null)
            {
                ArrayPool<byte>.Shared.Return(array);
            }
        }

        ThrowOnBadString();
        return null; // not reached
    }

    [LibraryImport(LibFile, EntryPoint = "thermo3_getName")]
    private static partial int _thermo3_getName(ThermoPhaseHandle handle, int bufLen, Span<byte> buf);



    static void ThrowOnBadString() =>
        throw new InvalidOperationException("Could not retrieve a string value from Cantera!");s
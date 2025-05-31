

    [CustomMarshaller(typeof(bool), MarshalMode.ManagedToUnmanagedOut, typeof(BoolReturnMarshaller))]
    static class BoolReturnMarshaller
    {
        public static bool ConvertToManaged(int value)
        {
            if (value is -1 or -2 or -999)
            {
                CanteraException.ThrowLatest();
            }

            return value != 0;
        }
    }
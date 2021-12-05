package com.aor.numbers;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.mockito.Mockito;

import java.util.Arrays;
import java.util.List;

public class ListDeduplicatorTest {

    private List<Integer> list;

    @BeforeEach
    public void createRandomList() {
        list = Arrays.asList(1,2,4,2,5);
    }

    @Test
    public void deduplicate() {
        List<Integer> expected = Arrays.asList(1,2,4,5);
        ListDeduplicator deduplicator = new ListDeduplicator();
        GenericListSorter sorter = Mockito.mock(GenericListSorter.class);
        Mockito.when(sorter.sort(Mockito.anyList())).thenReturn(Arrays.asList(1,2,2,4,5));
        List<Integer> distinct = deduplicator.deduplicate(list, sorter);

        Assertions.assertEquals(expected, distinct);
    }

    @Test
    public void deduplicate_bug_8726() {
        list = Arrays.asList(1,2,4,2);
        List<Integer> expected = Arrays.asList(1,2,4);
        ListDeduplicator deduplicator = new ListDeduplicator();
        GenericListSorter sorter = Mockito.mock(GenericListSorter.class);
        Mockito.when(sorter.sort(Mockito.anyList())).thenReturn(Arrays.asList(1,2,2,4));
        List<Integer> distinct = deduplicator.deduplicate(list, sorter);

        Assertions.assertEquals(expected, distinct);
    }
}
